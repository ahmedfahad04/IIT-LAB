package Observer_Pattern;

public class ClockTimer extends Subject{
    public ClockTimer(){};

    public int GetHour() {return 0;}
    public int GetMinute() {return 0;}
    public int GetSecond() {return 0;}

    void Tick(){
        // update internal time keeping state
        // it's a like a click event
        Notify();
    }
}
