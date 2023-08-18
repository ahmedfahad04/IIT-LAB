package design_patterns.behavioral.observer.observers;

import design_patterns.behavioral.observer.Subject;

public abstract class Observer {
    protected Subject subject;
    public abstract void update();

}
