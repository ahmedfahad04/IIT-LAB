package singleton;

import java.util.ArrayList;
import java.util.List;

public class MainWindow {

    private static MainWindow instance;
    private final List<Widgets> widgetName = new ArrayList<Widgets>();
    private MainWindow() {};

    public static MainWindow getInstance(){
        return (instance==null)? new MainWindow(): instance;
    }

    public void addWidget(Widgets widgets) {
        widgetName.add(widgets);
    }

    public void getWidgetNames() {
        for(Widgets widget: widgetName){
            System.out.println(widget.getObjectName());
        }
    }
}
