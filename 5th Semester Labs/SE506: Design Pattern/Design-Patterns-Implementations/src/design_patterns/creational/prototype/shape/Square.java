package design_patterns.creational.prototype.shape;

public class Square extends Shape{
    public Square() {
        type = "Square";
    }

    @Override
    void draw() {
        System.out.println("Inside Square   :: draw() method");
    }
}
