package Chain_of_Responsibility;

public abstract class HelpHandler {

    private HelpHandler successsor;
    Topic.Topics t = null;

    public HelpHandler(HelpHandler helpHandler , Topic.Topics topic){
        helpHandler = null;
        // problem
    };

    public boolean hasHelp() {
        return t != Topic.Topics.NO_HELP_TOPIC;
    };

    public void SetHandler(HelpHandler helpHandler, Topic t){
        return;
    };

    public void HandleHelp() {
        if (successsor != null) {
            successsor.HandleHelp();
        }
    };

}
