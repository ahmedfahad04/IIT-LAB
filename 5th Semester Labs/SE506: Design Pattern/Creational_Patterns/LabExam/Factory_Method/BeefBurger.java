package LabExam.Factory_Method;

public class BeefBurger implements Burger{

    @Override
    public void prepare() {
        System.out.println("Preparing Beef Burger...");
    }
}
