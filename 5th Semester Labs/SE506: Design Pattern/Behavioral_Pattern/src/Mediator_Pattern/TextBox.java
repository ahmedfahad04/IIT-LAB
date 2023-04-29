package Mediator_Pattern;

public class TextBox extends Widget{

    String text = "";

    public TextBox() {
        System.out.println("Entered Text: " + text);
    }

    public void setText(String text) {
        this.text = text;
    }

    public String getText() {
        return this.text;
    }

    @Override
    public void execute() {
        mediator.notifyChanges(this);
    }
}
