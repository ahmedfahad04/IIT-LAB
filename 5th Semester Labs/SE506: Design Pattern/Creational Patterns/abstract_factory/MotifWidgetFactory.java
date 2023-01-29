package abstract_factory;

public class MotifWidgetFactory extends WidgetFactory {


    @Override
    public Widget CreateWidget() {
        System.out.println("Motif Widget created");
        return new Widget();
    }

    // familiy of products
    @Override
    public ScrollBar CreateScrollBar() {
        return new MotifScrollBar();
    }

    @Override
    public Window CreateWindow() {
        return new MotifWindow();
    }
        
}
