package Mediator_Pattern;

public abstract class Widget {

    Mediator window = new MainWindow();

    abstract void execute();
}
