package Observer_Pattern_2.Main;

public interface Observer {

    // used interface, instead of abstract class. But is there any additional benefits?

    // represents file monitor
    void Update(Subject theChangedSubject);

}
