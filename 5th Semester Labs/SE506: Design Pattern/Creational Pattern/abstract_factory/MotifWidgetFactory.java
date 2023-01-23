package abstract_factory;

public class MotifWidgetFactory extends WidgetFactory {

    @Override
    public ScrollBar CreateScrollBar() {
        return new MotifScrollBar();
    }

    @Override
    public Window CreateWindow() {
        return new MotifWindow();
    }
        
}
