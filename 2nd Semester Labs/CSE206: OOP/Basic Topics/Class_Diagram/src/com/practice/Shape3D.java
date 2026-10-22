package com.practice;

public abstract class Shape3D implements Comparable{
    private final String color;
    private final boolean filled;

    public Shape3D(String color, boolean filled){
        this.color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    public boolean isFilled(){
        return filled;
    }

    abstract double area();
    abstract double volume();
    //comparable

    public int compareTo(Object o){
        return 0;
    }
}
