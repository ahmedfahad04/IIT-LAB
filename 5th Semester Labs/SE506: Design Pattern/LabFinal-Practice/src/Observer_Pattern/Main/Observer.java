package Observer_Pattern.Main;

public interface Observer {

    // used interface, instead of abstract class. But is there any additional benefits?

    // represents file monitor
    void Update(Subject theChangedSubject);

}
