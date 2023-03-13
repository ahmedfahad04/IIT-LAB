package Decorator_Pattern;

public class TextView extends VisualComponent{

    @Override
    public void draw() {
        System.out.println("Drawing TextView");
    }

    @Override
    public void resize() {
        System.out.println("Resizing TextView");
    }
}
