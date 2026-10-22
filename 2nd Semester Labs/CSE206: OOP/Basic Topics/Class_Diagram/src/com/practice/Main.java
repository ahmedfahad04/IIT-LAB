package com.practice;

public class Main {

    public static void main(String[] args) {
	    Sphere obj1 = new Sphere("Red", true, 5.00);
        System.out.println(obj1.toString());
        System.out.println("Is it Filled: " + obj1.isFilled() + "\n");

        Cube obj2 = new Cube("Blue", false, 7.00);
        System.out.println(obj2.toString());
        System.out.println("Color: " + obj1.getColor() + "\n");


    }
}
