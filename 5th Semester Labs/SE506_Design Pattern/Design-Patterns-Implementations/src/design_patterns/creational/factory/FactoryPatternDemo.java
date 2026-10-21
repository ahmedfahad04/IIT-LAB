package design_patterns.creational.factory;

public class FactoryPatternDemo {
    public static void main(String[] args) {


        ShapeFactory shapeFactory = new ShapeFactory();

        Shape shape1 = shapeFactory.getShape("CIRCLE");
        Shape shape3 = shapeFactory.getShape("SQUARE");

        shape1.draw();
        shape3.draw();

    }
}
