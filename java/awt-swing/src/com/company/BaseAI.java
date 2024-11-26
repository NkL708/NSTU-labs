package com.company;

public abstract class BaseAI extends Thread
{
    private static int speed;
    private boolean isActive = true;
    private boolean isPaused = true;

    public void setActive(boolean active) {
        isActive = active;
    }

    public boolean isActive() {
        return isActive;
    }

    public void setPaused(boolean paused) {
        isPaused = paused;
    }

    public boolean isPaused() {
        return isPaused;
    }

    public static void setSpeed(int value) {
        speed = value;
    }

    public static int getSpeed() {
        return speed;
    }
}