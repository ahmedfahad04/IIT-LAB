package edu.cmu.hcii.paint;

import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            PaintWindow window = new PaintWindow(200, 300);
            window.setVisible(true);
            window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            window.setTitle("Paint Application");
            window.setSize(800, 600);
        });
    }
}