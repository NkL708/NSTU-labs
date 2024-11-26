package com.company;
import javax.swing.*;
import java.awt.*;
import java.io.Serializable;

public class RabbitAlbino extends Animal implements Serializable
{
    private static final Image image = new ImageIcon("src/com/company/images/rabbit_albino.jpg").getImage();
    private static int size = 0;

    public static int getSize() {
        return size;
    }

    public static void setSize(int value) {
        size = value;
    }

    public static Image getImage() {
        return image;
    }

    RabbitAlbino(int x, int y, Habitat habitat) {
        super(x,y, habitat);
        setAlbino(true);
        habitat.getVector().add(this);
    }
}