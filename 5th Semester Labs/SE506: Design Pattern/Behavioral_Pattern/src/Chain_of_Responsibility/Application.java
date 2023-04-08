package Chain_of_Responsibility;

public class Application extends HelpHandler{

    public Application(Topic.Topics t) {
        super(null, t);
    }

    public void HandleHelp(){
        System.out.println("List of Help topics");
        return;
    };
}
