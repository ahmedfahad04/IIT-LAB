package Observer_Pattern;

import java.util.ArrayList;
import java.util.List;

public class Subject {

    public Subject() {};
    List<Observer> observers = new ArrayList<>();

    public void attach(Observer observer){
        observers.add(observer);
    }

    public void detach(Observer observer) {
        observers.remove(observer);
    }

    public void Notify() {
        for(Observer observer: observers){
            observer.Update(this);
        }
    }
}
