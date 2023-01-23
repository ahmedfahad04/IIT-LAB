package abstract_factory;

public class client {
    public static void main(String[] args) {
        WidgetFactory widgetFactory = new MotifWidgetFactory();
        widgetFactory.CreateScrollBar();
        widgetFactory.CreateWindow();
    }
}
