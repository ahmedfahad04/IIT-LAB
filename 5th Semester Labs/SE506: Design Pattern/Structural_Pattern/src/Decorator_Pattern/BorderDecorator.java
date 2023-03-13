package Decorator_Pattern;

public class BorderDecorator extends Decorator{

    private int width;
    BorderDecorator(VisualComponent visualComponent) {
        super(visualComponent);
    }

    private void DrawBorder(int width){
        System.out.println("Drawing border");
    };

    @Override
    public void draw() {
        super.draw();
        DrawBorder(width);
    }
}
