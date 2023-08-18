package design_patterns.creational.prototype;

import design_patterns.creational.prototype.shape.Shape;
import design_patterns.creational.prototype.shape.ShapeCache;

public class Driver {
    public static void main(String[] args) {
        ShapeCache.loadCache();

        Shape shape1 = (Shape) ShapeCache.getShape("1");
        System.out.println("Shape   :" + shape1.getType());

        Shape shape2 = (Shape) ShapeCache.getShape("2");
        System.out.println("Shape   :" + shape2.getType());

        Shape shape3 = (Shape) ShapeCache.getShape("3");
        System.out.println("Shape   :" + shape3.getType());



    }
}
