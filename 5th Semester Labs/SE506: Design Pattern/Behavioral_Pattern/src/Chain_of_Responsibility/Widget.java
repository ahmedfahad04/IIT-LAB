package Chain_of_Responsibility;

public abstract class Widget extends HelpHandler{

    private Widget parent;

    public Widget(HelpHandler parent, Topic.Topics t) {
        super(parent, t);
    }

}
