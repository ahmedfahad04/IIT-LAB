package design_patterns.creational.factory;

public class Square implements Shape{

    @Override
    public void draw() {
        System.out.println("Drawing Square");
    }

    @Override
    public boolean matchName(String name) {
        if (name.equals("SQUARE")) {
            return true;
        }
        else return false;
    }

}
