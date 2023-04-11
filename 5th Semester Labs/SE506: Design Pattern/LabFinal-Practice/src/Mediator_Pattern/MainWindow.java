package Mediator_Pattern;

public class MainWindow extends Mediator {

    @Override
    void notifyChanges(Widget widget) {
        if (widget instanceof TextBox){
            // have to provide specific implementation
            System.out.println(((TextBox) widget).getText());
        } else if (widget instanceof Button) {
            System.out.println(((Button) widget).getState());
        }
    }
}
