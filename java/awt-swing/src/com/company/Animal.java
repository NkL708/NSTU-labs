package com.company;

import java.io.Serializable;
import java.util.Random;

public abstract class Animal implements Serializable
{
    private boolean isAlbino;
    private int x,y;
    private final static int ImgSize = 50;
    private int id;
    private final double timeOfBirth;
    private static double rabbitLifeTime, rabbitAlbinoLifeTime;
    private final int direction;

    Animal(int x,int y, Habitat habitat) {
        Random random = new Random();
        this.x = x;
        this.y = y;
        timeOfBirth = habitat.getSettings().getTime();
        direction = 1 + random.nextInt(2);
        id = random.nextInt(9999);
        while (habitat.getTreeSet().contains(id))
            id = random.nextInt(9999);
        habitat.getTreeSet().add(id);
        habitat.getHashMap().put(id,timeOfBirth);
    }

    public int getDirection() {
        return direction;
    }

    static public double getRabbitLifeTime() {
        return rabbitLifeTime;
    }

    static public void setRabbitLifeTime(double value) {
        rabbitLifeTime = value;
    }

    static public double getRabbitAlbinoLifeTime() {
        return rabbitAlbinoLifeTime;
    }

    static public void setRabbitAlbinoLifeTime(double value) {
        rabbitAlbinoLifeTime = value;
    }

    public double getTimeOfBirth() {
        return timeOfBirth;
    }

    public int getId() {
        return id;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int value) {
        x = value;
    }

    public void setY(int value) {
        y = value;
    }

    public boolean getAlbino() {
        return isAlbino;
    }

    public void setAlbino(boolean value) {
        isAlbino = value;
    }

    static public int getImgSize() {
        return ImgSize;
    }
}