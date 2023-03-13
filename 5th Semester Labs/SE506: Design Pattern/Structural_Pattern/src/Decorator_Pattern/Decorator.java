package Decorator_Pattern;

public class Decorator extends VisualComponent{

    private final VisualComponent component;

    Decorator(VisualComponent visualComponent) {
        this.component = visualComponent;
    }

    public void draw() {
        component.draw();
    };

    public void resize(){
        component.resize();
    };
}
