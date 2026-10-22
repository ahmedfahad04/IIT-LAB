package com.practice;

public class Cube extends Shape3D{
    private double side;

    public Cube(String color, boolean filled, double side){
        super(color, filled);
        this.side = side;
    }

    @Override
    double area() {
        return 6*side*side;
    }

    @Override
    double volume() {
        return Math.pow(side,3);
    }

    @Override
    public String toString() {
        return "Cube{" + "\n"+
                "side = " + side + "\n"+
                "Area = " + area() + "\n"+
                "Volume = " + volume() + "\n"+
                '}';
    }


    @Override
    public int compareTo(Object o) {
        return 0;
    }
}
