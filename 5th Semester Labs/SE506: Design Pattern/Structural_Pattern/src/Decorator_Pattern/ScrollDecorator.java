package Decorator_Pattern;

public class ScrollDecorator extends Decorator{

    ScrollDecorator(VisualComponent visualComponent) {
        super(visualComponent);
    }

    private void DrawScrollBar(){
        System.out.println("Adding scroll bar");
    };

    @Override
    public void draw() {
        super.draw();
        DrawScrollBar();
    }
}
