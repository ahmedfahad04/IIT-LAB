package design_patterns.creational.abstract_factory;

import design_patterns.creational.abstract_factory.color.ColorFactory;
import design_patterns.creational.abstract_factory.shape.ShapeFactory;

public class FactoryProducer {
    public static AbstractFactory getFactory(String choice){
        if(choice.equalsIgnoreCase("SHAPE")){
            return new ShapeFactory();
        }else if(choice.equalsIgnoreCase("COLOR")){
            return new ColorFactory();
        }
        return null;
    }
}
