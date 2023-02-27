package Observer_Pattern;

public class AnalogClock extends Observer{

    private ClockTimer clocktimer;

    public AnalogClock(ClockTimer clocktimer){
        this.clocktimer = clocktimer;
        this.clocktimer.attach(this);
    }
    @Override
    public void Update(Subject theChangedSubject) {
        System.out.println(theChangedSubject.toString());
    }

    public void Draw() {}
}
