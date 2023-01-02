package ProCodeSmellRemoved.FizzBuzz;

public class FizzBuzzNumber implements FizzStrategy{
    @Override
    public String getResponse() {
        return "FizzBuzz";
    }

    @Override
    public boolean match(int number) {
        return number % 15 == 0;
    }
}
