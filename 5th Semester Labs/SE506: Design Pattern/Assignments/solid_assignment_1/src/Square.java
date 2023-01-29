class Square implements Shape {

    double side;

    public Square(double side) {
        this.side = side;
    }

    void setSize(double s) {
        this.side = s;
    }

    @Override
    public double calculateArea() {
        System.out.print("Square Area: ");
        return side * side;
    }

    @Override
    public void setTopLeft(double x, double y) {
        // implementation
    }

    @Override
    public void draw() {
        System.out.print("Square - ");
    }
}
