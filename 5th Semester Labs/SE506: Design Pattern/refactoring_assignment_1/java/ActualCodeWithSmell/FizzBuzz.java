package ActualCodeWithSmell;

/**
 * Requirements:
 * For factor of three print Fizz instead of the number
 * For factor of five print Buzz instead of the number
 * For numbers which are factors of both three and five print FizzBuzz instead of the number
 */

public class FizzBuzz {
    public static String say(int number) {
        String strReturn = null;

        if (number % 15 == 0) {
            strReturn = "FizzBuzz";
        } else {
            if (number % 3 == 0) strReturn = "Fizz";

            if (number % 5 == 0) strReturn = "Buzz";
        }

        if (strReturn != null) return strReturn;

        return String.valueOf(number);
    }
}
