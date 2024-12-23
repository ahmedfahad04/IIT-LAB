package OOP;

public class Circle extends Shape {
    double radius = 0;

    public Circle (double r) {
        this.radius = r;
    }

    @Override
    public double calculateArea(double radius) {
        double rad = radius != 0 ? radius : this.radius;
        return 3.14*rad*rad;
    }
}