package abstract_factory;

public abstract class WidgetFactory {

    // factory method
    public abstract Widget CreateWidget();
    public abstract ScrollBar CreateScrollBar();
    public abstract Window CreateWindow();      

}
