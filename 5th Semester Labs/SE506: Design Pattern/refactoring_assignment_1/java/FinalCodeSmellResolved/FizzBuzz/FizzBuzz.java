package FinalCodeSmellResolved.FizzBuzz;

import java.util.List;

/**
 * Requirements:
 * For factor of three print Fizz instead of the number
 * For factor of five print Buzz instead of the number
 * For numbers which are factors of both three and five print FizzBuzz instead of the number
 */

/*
    1. Duplicate Code [resolve: strategy Pattern]
    {if-else ladder}

    2. Temporary Field  [resolve: delete field]
    {strReturn}
*/

public class FizzBuzz {

    private static final List<FizzStrategy> strategies = List.of (
            new FizzBuzzNumber(),
            new FizzNumber(),
            new BuzzNumber()
    );

    public String say(int number) {

        for(FizzStrategy fizzStrategy: strategies) {
            if(fizzStrategy.match(number)) return fizzStrategy.getResponse();
        }

        return String.valueOf(number);
    }

   public static void main(String[] args) {
       FizzBuzz fizzBuzz = new FizzBuzz();
       System.out.println(fizzBuzz.say(3));
   }

}
