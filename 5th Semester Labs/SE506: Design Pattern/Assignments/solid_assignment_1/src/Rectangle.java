class Rectangle implements Shape {
    double width;
    double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public void setSize(double w, double h) {
        this.width = w;
        this.height = h;
    }

    @Override
    public double calculateArea() {
        System.out.print("Rectangle Area: ");
        return width * height;
    }

    @Override
    public void setTopLeft(double x, double y) {
        // implementation
    }

    @Override
    public void draw() {
        // implementation
    }
}
