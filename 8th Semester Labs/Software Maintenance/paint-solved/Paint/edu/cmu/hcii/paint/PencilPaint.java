package edu.cmu.hcii.paint;

import java.awt.*;

public class PencilPaint extends PaintObject {

    Point[] points;
    
    public PencilPaint() {
     
    }
    
    public double getStartX() { return points[0].getX(); }
    public double getStartY() { return points[0].getY(); }
    public double getEndX() { return points[points.length - 1].getX(); }
    public double getEndY() { return points[points.length - 1].getY(); }
    
    public void define(Point[] points) {
        
        this.points = points;
        
    }
    
    public Rectangle getBoundingBox() {
        
		int minX = 100000, minY = 100000;
		int maxX = 0, maxY = 0;
		
		for(int pointIndex = points.length - 1; pointIndex >= 0; pointIndex--) {
            
            int x = (int)points[pointIndex].getX();
            int y = (int)points[pointIndex].getY();
			if(x - thickness / 2 < minX) minX = x - thickness / 2;
			else if(x + thickness / 2 > maxX) maxX = x + thickness / 2;
			if(y - thickness / 2 < minY) minY = y - thickness / 2;
			else if(y + thickness / 2 > maxY) maxY = y + thickness / 2;
            
		}
        
		return new Rectangle(minX, minY, maxX - minX, maxY - minY);
        
    }
    
    public void paint(Graphics2D g) {
                
        Stroke oldStroke = g.getStroke();
        g.setStroke(new BasicStroke(thickness));
        g.setColor(color);
        
        for(int pointIndex = points.length - 1; pointIndex >= 1; pointIndex--) {
            
            Point one = points[pointIndex];
            Point two = points[pointIndex - 1];
            g.drawLine((int)one.getX(), (int)one.getY(), (int)two.getX(), (int)two.getY());            
            
        }
        
        g.setStroke(oldStroke);        
        
    }
    
}
