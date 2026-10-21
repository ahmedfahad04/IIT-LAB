package edu.cmu.hcii.paint;
import java.util.*;
import java.awt.event.*;
import java.awt.*;

public class PaintObjectConstructor implements MouseListener, MouseMotionListener {

    private Vector pointsGathered;
    private PaintObjectConstructorListener constructorListener;
    private Class paintObjectClass;
    private PaintObject temporaryObject;
    
    private Color color;
    private int thickness;
    
    public PaintObjectConstructor(PaintObjectConstructorListener listener) {
        
        this.constructorListener = listener;
        
    }
    
    public void setThickness(int thickness) { this.thickness = thickness; }
    public void setColor(Color color) { this.color = color; }
    public Color getColor() { return this.color; }
    public void setClass(Class paintObjectClass) { this.paintObjectClass = paintObjectClass; }
    
	public void mouseClicked(MouseEvent e) {} 
    public void mouseEntered(MouseEvent e) {} 
    
    public void mouseExited(MouseEvent e) {
    
		constructorListener.hoveringOverConstructionArea(null);
    
    } 

    public void mouseMoved(MouseEvent e) {
    
		constructorListener.hoveringOverConstructionArea(makeHoveringPrototype(e.getPoint()));
    
    }
    
    public void mousePressed(MouseEvent e) {
        
        pointsGathered = new Vector();
        pointsGathered.addElement(e.getPoint());
        
        try {
            temporaryObject = (PaintObject)paintObjectClass.newInstance();
        } catch(Exception exception) { 
        	System.err.println("There was a problem making the paint object.");
        }
        
        	temporaryObject.setColor(color);
        	temporaryObject.setThickness(thickness);
        
        	temporaryObject.define((Point[])pointsGathered.toArray(new Point[pointsGathered.size()]));
        	constructorListener.hoveringOverConstructionArea(makeHoveringPrototype(e.getPoint()));
        	constructorListener.constructionBeginning(temporaryObject);
        
    }
    
    public void mouseDragged(MouseEvent e) {
        
        	pointsGathered.addElement(e.getPoint());
        	temporaryObject.define((Point[])pointsGathered.toArray(new Point[pointsGathered.size()]));
        	constructorListener.hoveringOverConstructionArea(makeHoveringPrototype(e.getPoint()));
        	constructorListener.constructionContinuing(temporaryObject);
        
    }
    
    	public void mouseReleased(MouseEvent e) {
        
    		pointsGathered.addElement(e.getPoint());
    		temporaryObject.define((Point[])pointsGathered.toArray(new Point[pointsGathered.size()]));
    		constructorListener.constructionComplete(temporaryObject);
    		constructorListener.hoveringOverConstructionArea(null);
        
    		pointsGathered = null;
    		temporaryObject = null;
        
    }
    
    private PaintObject makeHoveringPrototype(Point p) {
    	
		PaintObject prototype = null;
		try {
			prototype = (PaintObject)paintObjectClass.newInstance();
		} catch(Exception exception) {
			System.err.println("There was a problem making the paint object.");
		}
		Point[] points = new Point[2];
		points[0] = points[1] = p;
		prototype.define(points);
		prototype.setColor(color);
		prototype.setThickness(thickness);

		return prototype;
			
    }

}
