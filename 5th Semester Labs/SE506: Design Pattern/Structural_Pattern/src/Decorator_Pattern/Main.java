package Decorator_Pattern;

public class Main {
    public static void main(String[] args) {
        Window window = new Window();
        window.SetContent(new BorderDecorator(new ScrollDecorator(new TextView())));
    }
}