package abstract_factory;

public class WidgetMaker {
    
    public Widget createWidget(WidgetFactory widgetFactory){
        Widget widget = widgetFactory.CreateWidget();

        ScrollBar scrollBar = widgetFactory.CreateScrollBar();
        Window window = widgetFactory.CreateWindow();

        widget.addScrollBar(scrollBar);
        widget.addWindow(window);
        
        return widget;
    }
}
