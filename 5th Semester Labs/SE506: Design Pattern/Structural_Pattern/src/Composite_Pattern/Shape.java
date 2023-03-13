package Composite_Pattern;

import java.util.ArrayList;
import java.util.List;

public abstract class Shape {

    List<Line> lines = new ArrayList<Line>();

    public abstract void  draw();

}
