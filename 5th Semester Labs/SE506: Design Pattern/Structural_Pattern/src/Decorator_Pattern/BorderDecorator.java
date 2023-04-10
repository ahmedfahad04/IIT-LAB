package Decorator_Pattern;

public class BorderDecorator extends BaseDecorator {

    private int width = 5;

    BorderDecorator(VisualComponent visualComponent) {
        super(visualComponent);
    }

    private void DrawBorder(int width){
        System.out.println("Drawing border: width="+width);
    };

    @Override
    public void draw() {
        super.draw();
        DrawBorder(width);
    }
}
