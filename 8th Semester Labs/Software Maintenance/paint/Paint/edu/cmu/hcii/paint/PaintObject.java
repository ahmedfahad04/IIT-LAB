package edu.cmu.hcii.paint;
import java.awt.*;

public abstract class PaintObject {

    protected int thickness;
    protected Color color;
    
    public void setColor(Color color) { this.color = color; }
    public void setThickness(int thickness) { this.thickness = thickness; }
    
    public abstract double getStartX();
    public abstract double getStartY();
    public abstract double getEndX();
    public abstract double getEndY();
    
    public abstract Rectangle getBoundingBox();
    public abstract void paint(Graphics2D g);
    public abstract void define(Point[] points);
    
}
