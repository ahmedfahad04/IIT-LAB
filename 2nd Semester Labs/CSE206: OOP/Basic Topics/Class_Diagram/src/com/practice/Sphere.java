package com.practice;

public class Sphere extends Shape3D{
    private double radius;

    public Sphere(String color, boolean filled, double radius){
        super(color, filled);
        this.radius = radius;
    }


    @Override
    double area() {
        return 4*3.1416*radius*radius;
    }

    @Override
    double volume() {
        return (4/3.0)*3.1416*Math.pow(radius,3);
    }

    @Override
    public String toString() {
        return "Sphere{" + "\n"+
                "Radius= " + radius + "\n"+
                "Area = " + area() + "\n"+
                "Volume = " + volume() + "\n"+
                '}';
    }


    @Override
    public int compareTo(Object o) {
        return 0;
    }
}
