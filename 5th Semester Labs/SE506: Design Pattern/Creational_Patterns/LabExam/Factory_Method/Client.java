package LabExam.Factory_Method;

public class Client {

    public static void main(String[] args) {
        Restaurant beefRestaurant = new BeefBurgerRestaurant();
        Burger beefBurger = beefRestaurant.orderBurger();
    }


}
