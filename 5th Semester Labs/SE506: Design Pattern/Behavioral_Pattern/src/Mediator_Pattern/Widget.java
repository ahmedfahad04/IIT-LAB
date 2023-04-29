package Mediator_Pattern;

public abstract class Widget {

    Mediator mediator = new MainWindow();

    abstract void execute();
}
