package Mediator_Pattern;

public class Main {
    public static void main(String[] args) {
        TextBox textBox = new TextBox();
        textBox.setText("Mediator Pattern");
        textBox.execute();

        Button button = new Button();
        button.setState("Clicked!!");
        button.execute();
    }
}
