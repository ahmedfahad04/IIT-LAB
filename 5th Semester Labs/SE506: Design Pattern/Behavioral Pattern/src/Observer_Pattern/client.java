package Observer_Pattern;

public class client {
    public static void main(String[] args) {
        ClockTimer timer = new ClockTimer();
        AnalogClock analogclock = new AnalogClock(timer);
        DigitalClock digitalclock = new DigitalClock(timer);
    }
}
