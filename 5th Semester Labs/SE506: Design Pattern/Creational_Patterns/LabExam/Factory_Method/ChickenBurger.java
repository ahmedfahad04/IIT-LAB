package LabExam.Factory_Method;

public class ChickenBurger implements Burger{
    @Override
    public void prepare() {
        System.out.println("Preparing Chicken Burger...");
    }
}
