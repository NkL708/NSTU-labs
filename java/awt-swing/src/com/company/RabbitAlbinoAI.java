package com.company;

public class RabbitAlbinoAI extends BaseAI
{
    private final Habitat habitat;
    RabbitAlbinoAI(Habitat habitat) {
        this.habitat = habitat;
    }
    @Override
    public void run() {
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
                    if (obj.getAlbino()) {
                        switch (obj.getDirection()) {
                            case 1 -> obj.setX(obj.getX() + BaseAI.getSpeed());
                            case 2 -> obj.setX(obj.getX() - BaseAI.getSpeed());
                        }
                    }
                }
            }
        }
    }
}