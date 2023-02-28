public class Client {

    public static void main(String[] args) {
        Rectangle rect = new Rectangle();
        rect.addLine(2);
        rect.draw();

        Square square = new Square();
        square.addLine(4);
        square.draw();
    }
}
