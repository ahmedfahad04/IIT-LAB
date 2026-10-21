package design_patterns.structural.decorator;

public class Driver {
    public static void main(String[] args) {
        Shape circle = new Circle();

        Shape redCircle = new RedShapeDecorator(new Circle());

        Shape redRectangle = new RedShapeDecorator(new Rectangle());

        System.out.println("Circle with Normal borders:");
        circle.draw();

        System.out.println("Circle with Red borders:");
        redCircle.draw();

        System.out.println("Rectangle with Red borders:");
        redRectangle.draw();
    }
}
