package Observer_Pattern;


public class DigitalClock extends Observer{

    private ClockTimer clockTimer;

    public DigitalClock(ClockTimer clockTimer) {
        this.clockTimer = clockTimer;
        clockTimer.attach(this);
    }

    @Override
    public void Update(Subject theChangedSubject) {
        if (theChangedSubject == clockTimer) {
            Draw();
        }
    }

    public void Draw() {
        int hour = clockTimer.GetHour();
        int minute = clockTimer.GetMinute();
        int second = clockTimer.GetSecond();

        // draw the digital clock
    }


}
