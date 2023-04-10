package Observer_Pattern_2.Main;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class ConcreteObserver implements Observer{

    String observerName;

    public ConcreteObserver(String observerName) {
        this.observerName = observerName;
    }

    @Override
    public void Update(Subject theChangedSubject) {

        LocalDateTime myDateObj = LocalDateTime.now();
        DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");
        String formattedDate = myDateObj.format(myFormatObj);

        System.out.println(this.observerName + " => " + theChangedSubject.message + "[" + formattedDate + "]");
    }
}
