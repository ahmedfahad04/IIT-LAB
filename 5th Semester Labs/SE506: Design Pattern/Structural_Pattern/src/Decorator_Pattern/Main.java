package Decorator_Pattern;

public class Main {
    public static void main(String[] args) {
        Window window = new Window();
        TextView textView = new TextView();

        window.SetContent(new BorderDecorator(new ScrollDecorator(textView)));
    }
}