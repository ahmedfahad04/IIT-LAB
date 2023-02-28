public class Square extends CompositeShape{
    
    @Override
    public void addLine(int numberOfLines) {
        for (int i=0; i<numberOfLines; i++) {
            lines.add(new Line());
        }
    }

    @Override
    public void removeLine(int numberOfLines) {
        for (int i=0; i<numberOfLines; i++) {
            lines.remove(new Line());
        }
    }
}
