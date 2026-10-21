package edu.cmu.hcii.paint;
import javax.swing.*;
import java.awt.event.*;

public class Actions {

    public AbstractAction clearAction, undoAction, pencilAction, eraserAction;
    
    private PaintWindow paintWindow;
    
    public Actions(PaintWindow window) {
    
        this.paintWindow = window;
        
        clearAction = new AbstractAction() {
            public void actionPerformed(ActionEvent actionEvent) {
                
                paintWindow.clear();
                
            }
        };
        clearAction.putValue(Action.NAME, "Clear the canvas");
        
        undoAction = new AbstractAction() {
            public void actionPerformed(ActionEvent actionEvent) {
                
                paintWindow.undo();
                
            }
        };
        undoAction.putValue(Action.NAME, "Undo my last stroke");
        
        pencilAction = new AbstractAction() {
            public void actionPerformed(ActionEvent actionEvent) {
                
                paintWindow.setPaintObjectClass(PencilPaint.class);                
                
            }
        };
        pencilAction.putValue(Action.NAME, "Pencil");
        
        eraserAction = new AbstractAction() {
            public void actionPerformed(ActionEvent actionEvent) {
                
                paintWindow.setPaintObjectClass(EraserPaint.class);
                
            }
        };
        eraserAction.putValue(Action.NAME, "Eraser"); 
        
    }
        
}
