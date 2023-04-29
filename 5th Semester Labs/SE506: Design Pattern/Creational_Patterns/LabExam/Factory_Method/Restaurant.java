package LabExam.Factory_Method;

public abstract class Restaurant {
    public Burger orderBurger() {
        Burger burger = createBurger();
        burger.prepare();
        return burger;
    }

    // I'll get the related burger through this function

    public abstract Burger createBurger();
}
