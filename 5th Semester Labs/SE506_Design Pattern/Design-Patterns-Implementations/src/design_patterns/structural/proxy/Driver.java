package design_patterns.structural.proxy;

public class Driver {
    public static void main(String[] args) {
        Image image = new ProxyImage("test_10mb.jpg");

        image.display();
        System.out.println("");

        image.display();
    }
}
