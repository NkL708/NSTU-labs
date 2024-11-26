package com.company;

import java.util.Random;

public class RabbitAI extends BaseAI
{
    Habitat habitat;
    RabbitAI(Habitat habitat) {
        this.habitat = habitat;
    }
    @Override
    public void run() {
        Random random = new Random();
        while (isActive()) {
            while (isPaused())
                Thread.onSpinWait();
            try {
                sleep(habitat.getSettings().getTimerPeriod());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            synchronized (habitat.getVector()) {
                for (Animal obj : habitat.getVector()) {
                    if (!obj.getAlbino()) {
                        int quadrant = 1 + random.nextInt(4);
                        switch (quadrant) {
                            case 1 -> {
                                obj.setX(obj.getX() + BaseAI.getSpeed());
                                obj.setY(obj.getY() + BaseAI.getSpeed());
                            }
                            case 2 -> {
                                obj.setX(obj.getX() - BaseAI.getSpeed());
                                obj.setY(obj.getY() + BaseAI.getSpeed());
                            }
                            case 3 -> {
                                obj.setX(obj.getX() - BaseAI.getSpeed());
                                obj.setY(obj.getY() - BaseAI.getSpeed());
                            }
                            case 4 -> {
                                obj.setX(obj.getX() + BaseAI.getSpeed());
                                obj.setY(obj.getY() - BaseAI.getSpeed());
                            }
                        }
                    }
                }
            }
        }
    }
}