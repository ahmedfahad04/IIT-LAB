package Mediator_Pattern;

public class Button extends Widget{

    String state = "enabled";

    public Button() {
        System.out.println("Current State: " + state);
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getState() {return this.state;}

    @Override
    void execute() {
        window.notifyChanges(this);
    }
}
