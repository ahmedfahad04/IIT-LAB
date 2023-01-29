package FinalCodeSmellResolved.FizzBuzz;

public class FizzNumber implements FizzStrategy {
    public String getResponse() {
        return "Fizz";
    }

    @Override
    public boolean match(int number) {
        return number % 3 == 0;
    }
}