package design_patterns.creational.abstract_factory;

import design_patterns.creational.abstract_factory.color.Color;
import design_patterns.creational.abstract_factory.shape.Shape;

public class AbstractFactoryPatternDemo {
    public static void main(String[] args) {
        AbstractFactory shapeFactory = FactoryProducer.getFactory("SHAPE");

        Shape shape1 = shapeFactory.getShape("SQUARE");
        Shape shape2 = shapeFactory.getShape("RECTANGLE");
        Shape shape3 = shapeFactory.getShape("CIRCLE");

        shape1.draw();
        shape2.draw();
        shape3.draw();

        AbstractFactory colorFactory = FactoryProducer.getFactory("COLOR");

        Color color1 = colorFactory.getColor("RED");
        Color color2 = colorFactory.getColor("BLUE");
        Color color3 = colorFactory.getColor("GREEN");

        color1.fill();
        color2.fill();
        color3.fill();

    }
}
