public class main {
    public static void main(String[] args) {
        Square s = new Square(25.0);
        s.setSize(50.0);
        s.area();

        Rectangle r = new Rectangle(15,20);
        r.setSize(25, 30);
        r.area();
    }
}