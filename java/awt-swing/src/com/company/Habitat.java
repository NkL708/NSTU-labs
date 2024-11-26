package com.company;
import javax.swing.*;
import javax.swing.Timer;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.atomic.*;

public class Habitat extends JPanel
{
    //Коллекции
    private final TreeSet<Integer> treeSet = new TreeSet<>();
    private final HashMap<Integer,Double> hashMap = new HashMap<>();
    private Vector <Animal> vector = new Vector<>();
    private final String[] percentBoxArr = {"10%","20%","30%","40%","50%","60%","70%","80%","90%","100%"};
    // Переменные для работы программы (почти все перешли в класс settings)
    private long timeStart;
    // Класс, который будет хранить наши настройки. Его можно сериализовать
    private Settings settings = new Settings(this);
    {
        settings.serialize();
    }
    // Сокет
    Socket socket;
    // Потоки
    private final RabbitAI rabbitAI = new RabbitAI(this);
    private final RabbitAlbinoAI rabbitAlbinoAI = new RabbitAlbinoAI(this);
    // Потоки ввода и вывода
    private final InputStream inputStream = new InputStream() {
        @Override
        public int read() {
            String text = consoleInput.getText();
            int count = 0;
            if (text.contains("Сократить число кроликов-альбиносов на ")) {
                count = RabbitAlbino.getSize() * Integer.parseInt(text.replaceAll("\\D", "")) / 100;
            }
            return count;
        }
    };

    // Графические компоненты
    private final Image background = new ImageIcon("src/com/company/images/background.png").getImage();
    private final JFrame jFrame = new JFrame("Безденежных АВТ-910");
    private final JPanel controlPanel = new JPanel();
    private final JButton startButton = new JButton("Старт");
    private final JButton stopButton = new JButton("Стоп");
    private final JButton clearButton = new JButton("Очистить");
    private final JButton currentObjButton = new JButton("Текущие объекты");
    private final JButton timeButton1 = new JButton("Включить время");
    private final JButton timeButton2 = new JButton("Выключить время");
    private final JButton rabbitAIStopButton = new JButton("Остановить кроликов");
    private final JButton rabbitAIResumeButton = new JButton("Возобновить кроликов");
    private final JButton rabbitAlbinoAIStopButton = new JButton("Остановить альбиносов");
    private final JButton rabbitAlbinoAIResumeButton = new JButton("Возобновить альбиносов");
    private final JButton consoleButton = new JButton("Открыть консоль");
    private final JTextField timerPeriodField = new JTextField(Double.toString(settings.getTimerPeriod() / 1000.),6);
    private final JTextField rabbitLifetimeField = new JTextField(Integer.toString(settings.getRabbitLifetime()),6);
    private final JTextField rabbitAlbinoLifetimeField = new JTextField(Integer.toString(settings.getRabbitAlbinoLifetime()),6);
    private final JTextField speedField = new JTextField(Integer.toString(settings.getSpeed()),6);
    private final JComboBox<String> rabbitChanceBox = new JComboBox<>(percentBoxArr);
    private final JComboBox<String> albinoPopulationSizeBox = new JComboBox<>(percentBoxArr);
    private final JLabel timeLabel = new JLabel();
    private final JTextArea statText = new JTextArea();
    private final JCheckBox modalAgreeBox = new JCheckBox("Разрешить всплывающее окно");
    // Диалоговое окно и его компоненты
    private final JDialog statDialog = new JDialog(jFrame, "",Dialog.ModalityType.DOCUMENT_MODAL);
    private final JButton dialogStopButton = new JButton("ОК");
    private final JButton dialogResumeButton = new JButton("Отмена");
    // Консоль
    private final JDialog console = new JDialog(jFrame, "");
    private final JTextPane consoleInput = new JTextPane();
    // Меню
    private final JMenuBar menuBar = new JMenuBar();
    private final JFileChooser jFileChooser = new JFileChooser("src/com/company/");
    private final JMenu menu = new JMenu("Меню");
    private final JMenuItem loadItem = new JMenuItem("Загрузить");
    private final JMenuItem saveItem = new JMenuItem("Сохранить");
    private final JMenuItem connectItem = new JMenuItem("Соединится с сервером");
    private final JMenuItem sendItem = new JMenuItem("Передать на сервер настройки");
    private final JMenuItem receiveItem = new JMenuItem("Получить с сервера настройки");

    Habitat() {
        createGUI();
        start();
    }

    public void setSettings(Settings settings) {
        this.settings = settings;
    }

    public Settings getSettings() {
        return settings;
    }

    public Vector<Animal> getVector() {
        return vector;
    }

    public TreeSet<Integer> getTreeSet() {
        return treeSet;
    }

    public HashMap<Integer,Double> getHashMap() {
        return hashMap;
    }

    public void updateTime()    // Обновление отображаемого времени
    {
        settings.setTime((double)(System.currentTimeMillis() - timeStart) / 1000);
        timeLabel.setText(Double.toString(settings.getTime()));
    }

    public void createGUI() // Создание графического интерфейса
    {
        // Свойства панелей программы и окна
        jFrame.setSize(800,600);
        jFrame.setLocationRelativeTo(null);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.add(controlPanel);
        jFrame.add(this);
        jFrame.setVisible(true);
        controlPanel.setBounds(0,0,200,jFrame.getMaximumSize().height);
        controlPanel.setBackground(Color.LIGHT_GRAY);
        setBounds(100,0,700,600);
        // Свойства компонент
        timerPeriodField.setToolTipText("Скорость появления всех кроликов (с)");
        rabbitLifetimeField.setToolTipText("Время жизни кроликов");
        rabbitAlbinoLifetimeField.setToolTipText("Время жизни кроликов-альбиносов");
        speedField.setToolTipText("Скорость движения всех кроликов");
        modalAgreeBox.setToolTipText("Разрешить отображение модального окна со статистикой");
        rabbitChanceBox.setToolTipText("Шанс появления кроликов");
        albinoPopulationSizeBox.setToolTipText("Максимальный размер кроликов-альбиносов от общего размера");
        timeLabel.setForeground(Color.BLACK);
        startButton.setBackground(Color.WHITE);
        stopButton.setBackground(Color.WHITE);
        clearButton.setBackground(Color.WHITE);
        currentObjButton.setBackground(Color.WHITE);
        modalAgreeBox.setBackground(Color.LIGHT_GRAY);
        modalAgreeBox.setSelected(settings.isModalAgree());
        dialogResumeButton.setBackground(Color.WHITE);
        dialogStopButton.setBackground(Color.WHITE);
        rabbitAIStopButton.setBackground(Color.WHITE);
        rabbitAIResumeButton.setBackground(Color.WHITE);
        rabbitAlbinoAIStopButton.setBackground(Color.WHITE);
        rabbitAlbinoAIResumeButton.setBackground(Color.WHITE);
        consoleButton.setBackground(Color.WHITE);
        timeButton1.setBackground(Color.WHITE);
        timeButton2.setBackground(Color.WHITE);
        rabbitChanceBox.setBackground(Color.WHITE);
        rabbitChanceBox.setSelectedIndex(settings.getRabbitChanceIndex());
        albinoPopulationSizeBox.setBackground(Color.WHITE);
        albinoPopulationSizeBox.setSelectedIndex(settings.getAlbinoPopulationSizeIndex());
        consoleInput.setBackground(Color.BLACK);
        consoleInput.setPreferredSize(new Dimension(350,325));
        consoleInput.setForeground(Color.GREEN);
        statText.setEditable(false);
        statText.setBackground(null);
        stopButton.setEnabled(false);
        timeButton1.setEnabled(false);
        // Добавление компонент на нашу панель
        controlPanel.add(startButton);
        controlPanel.add(stopButton);
        controlPanel.add(clearButton);
        controlPanel.add(currentObjButton);
        controlPanel.add(timerPeriodField);
        controlPanel.add(rabbitLifetimeField);
        controlPanel.add(rabbitAlbinoLifetimeField);
        controlPanel.add(speedField);
        controlPanel.add(rabbitChanceBox);
        controlPanel.add(albinoPopulationSizeBox);
        controlPanel.add(rabbitAIStopButton);
        controlPanel.add(rabbitAIResumeButton);
        controlPanel.add(rabbitAlbinoAIStopButton);
        controlPanel.add(rabbitAlbinoAIResumeButton);
        controlPanel.add(consoleButton);
        controlPanel.add(timeButton1);
        controlPanel.add(timeButton2);
        controlPanel.add(modalAgreeBox);
        controlPanel.add(timeLabel);
        // Диалоговое окно
        statDialog.setSize(350,300);
        statDialog.setLocationRelativeTo(null);
        statDialog.setLayout(new FlowLayout());
        statDialog.setResizable(false);
        statDialog.add(statText);
        statDialog.add(dialogStopButton);
        statDialog.add(dialogResumeButton);
        //
        console.setSize(350,300);
        console.setLocationRelativeTo(null);
        console.setLayout(new FlowLayout());
        console.add(consoleInput);
        // Меню
        jFrame.setJMenuBar(menuBar);
        menuBar.add(menu);
        menu.add(saveItem);
        menu.add(loadItem);
        menu.add(connectItem);
        menu.add(sendItem);
        menu.add(receiveItem);
    }

    @Override
    public void paintComponent(Graphics g)  // Метод отрисовки объектов
    {
        controlPanel.updateUI();
        super.paintComponent(g);    // Очистка графики
        g.drawImage(background, controlPanel.getWidth(),0, getWidth(), getHeight(),null);
        for (Animal obj : getVector()) // Отрисовка всех объектов в коллекции
        {
            if (obj.getAlbino())
                g.drawImage(RabbitAlbino.getImage(), obj.getX(), obj.getY(), Animal.getImgSize(), Animal.getImgSize(), null);
            else
                g.drawImage(Rabbit.getImage(), obj.getX(), obj.getY(), Animal.getImgSize(), Animal.getImgSize(),null);
        }
    }

    private void startTimer(Timer timer)  // Запуск таймеров
    {
        // Очистка коллекции
        repaint();
        timeStart = System.currentTimeMillis();
        settings.setRabbitChance(10 * (rabbitChanceBox.getSelectedIndex() + 1));
        settings.setRabbitPopulationSize((albinoPopulationSizeBox.getSelectedIndex() + 1) / 10.);
        try
        {
            // Получение данных из полей ввода
            settings.setTimerPeriod((int)(1000 * Double.parseDouble(timerPeriodField.getText())));
            Animal.setRabbitLifeTime(Double.parseDouble(rabbitLifetimeField.getText()));
            Animal.setRabbitAlbinoLifeTime(Double.parseDouble(rabbitAlbinoLifetimeField.getText()));
            BaseAI.setSpeed(Integer.parseInt(speedField.getText()));
        }
        catch (Exception ex)    // При неверном вводе данных
        {
            JOptionPane.showMessageDialog(null,"Введите корректные значения");
            timerPeriodField.setText("1");
            rabbitLifetimeField.setText("5");
            rabbitAlbinoLifetimeField.setText("5");
            speedField.setText("1");
        }
        // Запуск генерации
        timer.setDelay(settings.getTimerPeriod());
        timer.restart();
        rabbitAI.setPaused(false);
        rabbitAlbinoAI.setPaused(false);
        startButton.setEnabled(false);
        stopButton.setEnabled(true);
        connectItem.setEnabled(false);
        receiveItem.setEnabled(true);
    }

    private void stopTimer(Timer timer)   // Остановка таймеров
    {
        timer.stop();
        rabbitAI.setPaused(true);
        rabbitAlbinoAI.setPaused(true);
        startButton.setEnabled(true);
        stopButton.setEnabled(false);
        connectItem.setEnabled(true);
        receiveItem.setEnabled(false);
    }

    public void updateSettings() {
        settings.setModalAgree(modalAgreeBox.isSelected());
        settings.setSpeed(Integer.parseInt(speedField.getText()));
        settings.setRabbitLifetime(Integer.parseInt(rabbitLifetimeField.getText()));
        settings.setRabbitAlbinoLifetime(Integer.parseInt(rabbitAlbinoLifetimeField.getText()));
        settings.setTimerPeriod((int)(Double.parseDouble(timerPeriodField.getText()) * 1000));
        settings.setRabbitChanceIndex(rabbitChanceBox.getSelectedIndex());
        settings.setAlbinoPopulationSizeIndex(albinoPopulationSizeBox.getSelectedIndex());
    }

    public void updateForm() {
        modalAgreeBox.setSelected(settings.isModalAgree());
        speedField.setText(Integer.toString(settings.getSpeed()));
        rabbitLifetimeField.setText(Integer.toString(settings.getRabbitLifetime()));
        rabbitAlbinoLifetimeField.setText(Integer.toString(settings.getRabbitAlbinoLifetime()));
        timerPeriodField.setText(Double.toString(settings.getTimerPeriod() / 1000.));
        rabbitChanceBox.setSelectedIndex(settings.getRabbitChanceIndex());
        albinoPopulationSizeBox.setSelectedIndex(settings.getAlbinoPopulationSizeIndex());
    }

    public void start() {
        Random rnd = new Random();
        repaint();
        // Запуск потоков
        rabbitAI.start();
        rabbitAlbinoAI.start();
        // Инициализация таймера
        Timer timer = new Timer(settings.getTimerPeriod(), e -> {
            double sizeOfAlbino = RabbitAlbino.getSize();
            Random rand = new Random();
            int chance = rand.nextInt(100);
            if (chance < settings.getRabbitChance()) {
                updateTime();
                int x = controlPanel.getWidth() + rnd.nextInt(getWidth() - Animal.getImgSize() - controlPanel.getWidth());
                int y = rnd.nextInt(getHeight() - Animal.getImgSize());
                new Rabbit(x,y,this);
                Rabbit.setSize(Rabbit.getSize()+1);
            }
            if ((sizeOfAlbino / getVector().size()) < settings.getRabbitPopulationSize()) {
                updateTime();
                int x = controlPanel.getWidth() + rnd.nextInt(getWidth() - Animal.getImgSize() - controlPanel.getWidth());
                int y = rnd.nextInt(getHeight() - Animal.getImgSize());
                new RabbitAlbino(x,y,this);
                RabbitAlbino.setSize(RabbitAlbino.getSize()+1);
            }
            // Удаление данных из коллекций
            // Объекты Animal
            getVector().removeIf(obj -> {
                if (obj.getAlbino() && obj.getTimeOfBirth() + Animal.getRabbitAlbinoLifeTime() < settings.getTime())
                    RabbitAlbino.setSize(RabbitAlbino.getSize()-1);
                if (!obj.getAlbino() && obj.getTimeOfBirth() + Animal.getRabbitLifeTime() < settings.getTime())
                    Rabbit.setSize(RabbitAlbino.getSize()-1);
                return (obj.getAlbino() && obj.getTimeOfBirth() + Animal.getRabbitAlbinoLifeTime() < settings.getTime()) ||
                        (!obj.getAlbino() && obj.getTimeOfBirth() + Animal.getRabbitLifeTime() < settings.getTime());
            });
            // Уникальные id
            treeSet.removeIf(obj -> {
                for (Animal rabbit : getVector()) {
                    if (rabbit.getId() == obj)
                        return false;
                }
                return true;
            });
            // Хэш таблица: id-время рождения (ключ-значение)
            hashMap.keySet().removeIf(obj -> !treeSet.contains(obj));
            repaint();
        });

        // Определение всех действий кнопок
        startButton.addActionListener(e ->
                startTimer(timer));

        stopButton.addActionListener(e -> {
            stopTimer(timer);
            settings.setModalAgree(modalAgreeBox.isSelected());
            statText.setText("Кроликов альбиносов - " + RabbitAlbino.getSize() + ". Обычных кроликов - " + Rabbit.getSize());
            if (settings.isModalAgree())
                statDialog.setVisible(true);
        });

        clearButton.addActionListener(e -> {
            getVector().clear();
            Rabbit.setSize(0);
            RabbitAlbino.setSize(0);
        });

        currentObjButton.addActionListener(e -> {
            stopTimer(timer);
            String msg = "";
            int i = 0;
            for (Map.Entry<Integer, Double> obj : hashMap.entrySet()) {
                if (getVector().get(i).getAlbino())
                    msg = msg.concat("Альбинос ");
                else
                    msg = msg.concat("Кролик ");
                msg = msg.concat(obj.getKey() + " - " + obj.getValue() + "\n");
                i++;
            }
            statText.setText(msg);
            statDialog.setVisible(true);
        });

        timeButton1.addActionListener(e -> {
            timeLabel.setVisible(true);
            timeButton2.setEnabled(true);
            timeButton1.setEnabled(false);
        });

        timeButton2.addActionListener(e -> {
            timeLabel.setVisible(false);
            timeButton2.setEnabled(false);
            timeButton1.setEnabled(true);
        });

        rabbitAIStopButton.addActionListener(e -> rabbitAI.setPaused(true));

        rabbitAIResumeButton.addActionListener(e -> rabbitAI.setPaused(false));

        rabbitAlbinoAIStopButton.addActionListener(e -> rabbitAlbinoAI.setPaused(true));

        rabbitAlbinoAIResumeButton.addActionListener(e -> rabbitAlbinoAI.setPaused(false));

        dialogStopButton.addActionListener(e -> {
            stopTimer(timer);
            statDialog.setVisible(false);
        });

        dialogResumeButton.addActionListener(e -> {
            timer.start();
            rabbitAI.setPaused(false);
            rabbitAlbinoAI.setPaused(false);
            statDialog.setVisible(false);
            startButton.setEnabled(false);
            stopButton.setEnabled(true);
            connectItem.setEnabled(false);
            receiveItem.setEnabled(true);
        });

        consoleButton.addActionListener(e -> console.setVisible(true));

        // Консольные команды
        consoleInput.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    AtomicInteger count = new AtomicInteger();
                    try {
                        count.set(inputStream.read());
                    } catch (IOException ioException) {
                        ioException.printStackTrace();
                    }
                    getVector().removeIf(obj -> {
                        if (obj.getAlbino() && count.get() > 0) {
                            RabbitAlbino.setSize(RabbitAlbino.getSize()-1);
                            count.getAndDecrement();
                        }
                        return obj.getAlbino() && count.get() > 0;
                    });
                    consoleInput.setText(null);
                }
            }
        });

        saveItem.addActionListener(e1 -> {
            jFileChooser.showSaveDialog(null);
            try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(jFileChooser.getSelectedFile()))) {
                oos.writeObject(vector);
            } catch (IOException e2) {
                e2.printStackTrace();
            }
        });

        loadItem.addActionListener(e1-> {
            jFileChooser.showOpenDialog(null);
            try (ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream(jFileChooser.getSelectedFile()))) {
                vector = ((Vector<Animal>) objectInputStream.readObject());
            } catch (IOException | ClassNotFoundException e2) {
                e2.printStackTrace();
            }
            repaint();
        });

        connectItem.addActionListener(e1 -> {
            socket = new Socket();
            try {
                socket.connect(new InetSocketAddress("localhost", 25565));
            } catch (IOException e2) {
                e2.printStackTrace();
            }
        });

        sendItem.addActionListener(e1 -> {
            updateSettings();
            try (ObjectOutputStream objectOutputStream = new ObjectOutputStream(socket.getOutputStream())) {
                objectOutputStream.writeObject(settings);
            } catch (IOException e2) {
                e2.printStackTrace();
            }
        });

        receiveItem.addActionListener(e -> {
            try (ObjectInputStream objectInputStream = new ObjectInputStream(socket.getInputStream())) {
                settings = (Settings) objectInputStream.readObject();
            } catch (IOException | ClassNotFoundException e2) {
                e2.printStackTrace();
            }
            updateForm();
        });

        jFrame.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e1) {
                updateSettings();
                // Запись
                try (ObjectOutputStream objectOutputStream = new ObjectOutputStream(new FileOutputStream("src/com/company/settings.txt"))) {
                    objectOutputStream.writeObject(settings);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public static void main(String[] args) {
        new Habitat();
        // Добавь ещё вызов, если хочешь проверить передачу данных между сервером
        //new Habitat();
    }
}