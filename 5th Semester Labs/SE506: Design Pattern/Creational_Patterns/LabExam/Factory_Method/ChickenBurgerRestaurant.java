package LabExam.Factory_Method;

public class ChickenBurgerRestaurant extends Restaurant{
    @Override
    public Burger createBurger() {
        return new ChickenBurger();
    }
}
