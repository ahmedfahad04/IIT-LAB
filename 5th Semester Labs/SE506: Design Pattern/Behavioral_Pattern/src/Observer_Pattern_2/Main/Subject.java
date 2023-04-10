package Observer_Pattern_2.Main;

import java.util.ArrayList;
import java.util.List;

public class Subject {
    // represents a file

    String message;

    List<Observer> observers = new ArrayList<>();

    public void registerObserver(Observer observer){
        observers.add(observer);
    }

    public void unregisterObserver(Observer observer) {
        observers.remove(observer);
    }

    public void Notify(String message) {
        this.message = message;
        for(Observer observer: observers){
            observer.Update(this);
        }
    }
}
