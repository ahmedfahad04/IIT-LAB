package design_patterns.behavioral.observer;

import design_patterns.behavioral.observer.observers.BinaryObserver;
import design_patterns.behavioral.observer.observers.HexaObserver;
import design_patterns.behavioral.observer.observers.OctalObserver;

public class Driver {
    public static void main(String[] args) {
        Subject subject = new Subject();

        new HexaObserver(subject);
        new OctalObserver(subject);
        new BinaryObserver(subject);

        System.out.println("First state change: 15");
        subject.setState(15);

        System.out.println("First state change: 10");
        subject.setState(10);

    }
}
