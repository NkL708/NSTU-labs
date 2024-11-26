package com.company;

import java.io.*;

public class Settings implements Serializable
{
    private final File file = new File("src/com/company/","settings.txt");
    private final transient Habitat habitat;
    private boolean modalAgree;
    private int rabbitChance, timerPeriod, rabbitLifetime,
            rabbitAlbinoLifetime, speed, rabbitChanceIndex, albinoPopulationSizeIndex;
    private double rabbitPopulationSize, time;

    Settings(Habitat habitat) {
        this.habitat = habitat;
    }

    public void serialize() {
        // Загрузка настроек
        try (ObjectInputStream objectInputStream = new ObjectInputStream(new FileInputStream("src/com/company/settings.txt"))) {
            habitat.setSettings((Settings) objectInputStream.readObject());
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public int getRabbitChanceIndex() {
        return rabbitChanceIndex;
    }

    public void setRabbitChanceIndex(int rabbitChanceIndex) {
        this.rabbitChanceIndex = rabbitChanceIndex;
    }

    public int getAlbinoPopulationSizeIndex() {
        return albinoPopulationSizeIndex;
    }

    public void setAlbinoPopulationSizeIndex(int albinoPopulationSizeIndex) {
        this.albinoPopulationSizeIndex = albinoPopulationSizeIndex;
    }

    public boolean isModalAgree() {
        return modalAgree;
    }

    public void setModalAgree(boolean modalAgree) {
        this.modalAgree = modalAgree;
    }

    public int getRabbitChance() {
        return rabbitChance;
    }

    public void setRabbitChance(int rabbitChance) {
        this.rabbitChance = rabbitChance;
    }

    public int getTimerPeriod() {
        return timerPeriod;
    }

    public void setTimerPeriod(int timerPeriod) {
        this.timerPeriod = timerPeriod;
    }

    public double getRabbitPopulationSize() {
        return rabbitPopulationSize;
    }

    public void setRabbitPopulationSize(double rabbitPopulationSize) {
        this.rabbitPopulationSize = rabbitPopulationSize;
    }

    public double getTime() {
        return time;
    }

    public void setTime(double time) {
        this.time = time;
    }

    public int getRabbitLifetime() {
        return rabbitLifetime;
    }

    public void setRabbitLifetime(int rabbitLifetime) {
        this.rabbitLifetime = rabbitLifetime;
    }

    public int getRabbitAlbinoLifetime() {
        return rabbitAlbinoLifetime;
    }

    public void setRabbitAlbinoLifetime(int rabbitAlbinoLifetime) {
        this.rabbitAlbinoLifetime = rabbitAlbinoLifetime;
    }

    public void setSpeed(int speed) {
        this.speed = speed;
    }

    public int getSpeed() {
        return speed;
    }
}