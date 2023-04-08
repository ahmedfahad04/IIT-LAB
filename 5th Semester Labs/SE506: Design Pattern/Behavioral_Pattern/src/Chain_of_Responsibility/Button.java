package Chain_of_Responsibility;

public class Button extends Widget{

    Topic t;

    public Button(Widget parent, Topic.Topics t) {
        super(parent, t);
    }

    public void HandleHelp(){
        if (hasHelp()) {
            System.out.println(" offer help on the button");
        } else {
            super.HandleHelp();
        }
        return;
    };
}
