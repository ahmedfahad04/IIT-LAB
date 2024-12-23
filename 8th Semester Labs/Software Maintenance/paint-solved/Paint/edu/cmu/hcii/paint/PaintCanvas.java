package edu.cmu.hcii.paint;
import javax.swing.*;
import java.awt.*;
import java.util.*;

public class PaintCanvas extends JPanel {
    private int minWidth;
    private int minHeight;
    Vector history;
    Vector paintObjects;
    private PaintObject temporaryObject;
    private PaintObject hoveringObject;

    public PaintCanvas(int initialWidth, int initialHeight) {
        minWidth = initialWidth;
        minHeight = initialHeight;
        setPreferredSize(new Dimension(initialWidth, initialHeight));

        paintObjects = new Vector();
        history = new Vector();
    }

    private void updateCanvasSize(Rectangle bounds) {
        boolean needsResize = false;
        int newWidth = getPreferredSize().width;
        int newHeight = getPreferredSize().height;
        int padding = 50;

        if (bounds != null) {
            if (bounds.x + bounds.width + padding > newWidth) {
                newWidth = bounds.x + bounds.width + padding;
                needsResize = true;
            }

            // Check if we need to expand height
            if (bounds.y + bounds.height + padding > newHeight) {
                newHeight = bounds.y + bounds.height + padding;
                needsResize = true;
            }
        }

        if (needsResize) {
            setPreferredSize(new Dimension(
                    Math.max(minWidth, newWidth),
                    Math.max(minHeight, newHeight)
            ));
            revalidate();
        }
    }

    public void paintComponent(Graphics g) {
        // Set up anti-aliasing
        ((Graphics2D) g).addRenderingHints(
                new java.awt.RenderingHints(
                        java.awt.RenderingHints.KEY_ANTIALIASING,
                        java.awt.RenderingHints.VALUE_ANTIALIAS_ON));

        // Fill background
        Rectangle clipBounds = g.getClipBounds();
        g.setColor(Color.white);
        g.fillRect((int)clipBounds.getX(), (int)clipBounds.getY(),
                (int)clipBounds.getWidth(), (int)clipBounds.getHeight());

        // Paint all objects
        Iterator paintObjectIterator = paintObjects.iterator();
        while(paintObjectIterator.hasNext()) {
            try {
                PaintObject obj = (PaintObject)paintObjectIterator.next();
                obj.paint((Graphics2D)g);
                // Update canvas size based on object bounds
                updateCanvasSize(obj.getBoundingBox());
            } catch(Exception e) {
                System.err.println("The graphics context isn't a Graphics2D. No anti-aliasing!");
            }
        }

        // Paint temporary object
        if(temporaryObject != null) {
            temporaryObject.paint((Graphics2D)g);
            updateCanvasSize(temporaryObject.getBoundingBox());
        }

        // Paint hovering object
        if(hoveringObject != null) {
            Rectangle rect = hoveringObject.getBoundingBox();
            g.setColor(Color.black);
            g.drawRect((int)rect.getX() - 1, (int)rect.getY() - 1,
                    (int)rect.getWidth() + 2, (int)rect.getHeight() + 2);
            hoveringObject.paint((Graphics2D)g);
            updateCanvasSize(rect);
        }
    }

    public int sizeOfHistory() {
        return history.size();
    }

    public void setTemporaryObject(PaintObject temporaryObject) {
        this.temporaryObject = temporaryObject;
        if(temporaryObject != null) {
            updateCanvasSize(temporaryObject.getBoundingBox());
        }
        repaint();
    }

    public void setHoveringObject(PaintObject hoveringObject) {
        this.hoveringObject = hoveringObject;
        if(hoveringObject != null) {
            updateCanvasSize(hoveringObject.getBoundingBox());
        }
        repaint();
    }

    public void addPaintObject(PaintObject newObject) {
        history.addElement(new Vector(paintObjects));
        paintObjects.addElement(newObject);
        updateCanvasSize(newObject.getBoundingBox());
        repaint();
    }

    public void clear() {
        history.addElement(new Vector(paintObjects));
        paintObjects.removeAllElements();
        setPreferredSize(new Dimension(minWidth, minHeight));
        revalidate();
        repaint();
    }

    public void undo() {
        paintObjects = (Vector)history.lastElement();
        history.removeElement(history.lastElement());

        Dimension minSize = new Dimension(minWidth, minHeight);
        setPreferredSize(minSize);

        Iterator it = paintObjects.iterator();
        while(it.hasNext()) {
            PaintObject obj = (PaintObject)it.next();
            updateCanvasSize(obj.getBoundingBox());
        }

        revalidate();
        repaint();
    }
}