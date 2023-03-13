package Decorator_Pattern;

import java.util.ArrayList;
import java.util.List;

public class Window {

    public void SetContent(VisualComponent contents) {
        contents.draw();
    }
}
