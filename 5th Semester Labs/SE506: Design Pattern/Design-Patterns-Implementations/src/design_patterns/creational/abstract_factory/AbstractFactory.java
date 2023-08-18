package design_patterns.creational.abstract_factory;


import design_patterns.creational.abstract_factory.color.Color;
import design_patterns.creational.abstract_factory.shape.Shape;

public abstract class AbstractFactory {
    public abstract Color getColor(String color);
    public abstract Shape getShape(String shape);
}
