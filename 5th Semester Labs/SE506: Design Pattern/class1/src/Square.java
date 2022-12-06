public class Square extends Rectangle{

    double side;
    public Square(double side){
        super(side, side);
        this.side = side;
    }

    public void setSize(double a) {
        this.side = a;
        System.out.println("Side value changed to: "+ side);
    }

    public void setSize(double a, double b) {
        if(a != b) System.out.println("height and width can't be different");
        else System.out.println("New side is: "+a);
    }
}
