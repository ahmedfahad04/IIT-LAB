package design_patterns.creational.factory;

import java.util.List;

public class ShapeFactory {

    public List<Shape> shapes = List.of(
        new Circle(),
        new Rectangle(),
        new Square()
    );

//    use getShape method to get object of type shape
    public Shape getShape(String shapeType){

        if(shapeType == null){
            return null;
        }

        if(shapeType.equalsIgnoreCase("CIRCLE")){
            return new Circle();
        }else if(shapeType.equalsIgnoreCase("RECTANGLE")){
            return new Rectangle();
        }else if (shapeType.equalsIgnoreCase("SQUARE")){
            return new Square();
        }
        
        return null;

        // for(Shape shape: shapes) {
        //     if(shape.matchName(shapeType)) {
        //         return shape;
        //     }
        // }

        // return null;
    }
}
