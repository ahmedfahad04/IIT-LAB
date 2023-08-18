package design_patterns.creational.factory;

public class Rectangle implements Shape{
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }

    @Override
    public boolean matchName(String name) {
        if (name.equals("RECTANGLE")) {
            return true;
        }
        else return false;
    }
}
