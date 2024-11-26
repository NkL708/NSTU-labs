package com.company;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server implements Runnable {
    private Settings settings;
    private final ObjectInputStream objectInputStream;
    private final ObjectOutputStream objectOutputStream;


    Server(Socket socketSend, Socket socketReceive) throws IOException {
        objectInputStream = new ObjectInputStream(socketSend.getInputStream());
        objectOutputStream = new ObjectOutputStream(socketReceive.getOutputStream());
    }

    @Override
    public void run() {
        receive();
        send();
    }

    public void receive() {
        try {
            settings = (Settings) objectInputStream.readObject();
            System.out.println("Receiving message");
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void send() {
        try {
            objectOutputStream.writeObject(settings);
            System.out.println("Sending message");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException {
        try (ServerSocket serverSocket = new ServerSocket(25565)) {
            while (true) {
                Socket socketSend = serverSocket.accept();
                Socket socketReceive = serverSocket.accept();
                System.out.println("Clients connected");
                new Thread(new Server(socketSend,socketReceive)).start();
            }
        }
    }
}