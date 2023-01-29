package FinalCodeSmellResolved.FizzBuzz;

public class BuzzNumber implements FizzStrategy {
    public String getResponse() {
        return "Buzz";
    }

    @Override
    public boolean match(int number) {
        return number % 5 == 0;
    }
}