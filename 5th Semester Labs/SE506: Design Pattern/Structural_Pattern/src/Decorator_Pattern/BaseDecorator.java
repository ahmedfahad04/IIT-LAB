package Decorator_Pattern;

public class BaseDecorator extends VisualComponent{

    private final VisualComponent component;

    BaseDecorator(VisualComponent visualComponent) {
        this.component = visualComponent;
    }

    public void draw() {
        component.draw();
    };

    public void resize(){
        component.resize();
    };
}
