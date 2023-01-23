package abstract_factory;

public class PMWIdgetFactory extends WidgetFactory{


    // factory method 

    @Override
    public ScrollBar CreateScrollBar() {
        return new PMScrollBar();
    }

    @Override
    public Window CreateWindow() {
        return new PMWindow();
    }

}
