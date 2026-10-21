package design_patterns.creational.prototype.shape;

public class Circle extends Shape{
    public Circle() {
        type = "Circle";
    }

    @Override
    void draw() {
        System.out.println("Inside Circle   :: draw() method");
    }
}
