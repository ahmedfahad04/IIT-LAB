package design_patterns.creational.factory;

public class Circle implements Shape {

    @Override
    public void draw() {
        System.out.println("Drawing Circle");
    }

    @Override
    public boolean matchName(String name) {
        if (name.equals("CIRCLE")) {
            return true;
        }
        else return false;
    }

}
