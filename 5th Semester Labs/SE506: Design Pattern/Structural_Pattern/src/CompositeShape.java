public abstract class CompositeShape extends Shape implements ModifyShape {
    
    public void draw() {
        for (Line line : lines) {
            line.draw();
        }
    }   
}
