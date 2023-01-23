package abstract_factory;

public class PMWIdgetFactory extends WidgetFactory{

    @Override
    public ScrollBar CreateScrollBar() {
        return new PMScrollBar();
    }

    @Override
    public Window CreateWindow() {
        return new PMWindow();
    }

}
