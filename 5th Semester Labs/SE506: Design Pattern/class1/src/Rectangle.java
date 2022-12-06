public class Rectangle implements shape{

    double height;
    double width;

    public Rectangle(double a, double b) {
        this.height = a;
        this.width = b;
    }
    @Override
    public void area() {
        System.out.println("Area is: "+height*width);
    }

    public void setSize(double height, double width){
        this.height = height;
        this.width = width;
        System.out.printf("Rectangle dimension changed ");
    }
}
