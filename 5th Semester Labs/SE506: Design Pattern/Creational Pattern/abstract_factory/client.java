package abstract_factory;

public class client {
    public static void main(String[] args) {

        // IN that case, we must have at least two product class
        // here product class are Window and ScrollBar
        WidgetFactory widgetFactory = new MotifWidgetFactory();
        widgetFactory.CreateScrollBar();
        widgetFactory.CreateWindow();
    }
}
