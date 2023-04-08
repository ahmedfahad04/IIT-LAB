package Chain_of_Responsibility;

public class Dialog extends Widget {

    public Dialog(HelpHandler helpHandler, Topic.Topics t) {
        super(helpHandler, t);
    }

    public void SetHandler(HelpHandler helpHandler, Topic t){
        super.SetHandler(helpHandler, t);
    };

    public void HandleHelp(){
        if (hasHelp()) {
            System.out.println("offer help on the button");
        } else {
            super.HandleHelp();
        }
        return;
    };

}
