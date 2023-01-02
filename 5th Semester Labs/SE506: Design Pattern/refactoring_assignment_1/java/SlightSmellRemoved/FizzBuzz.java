package SlightSmellRemoved;

/**
 * Requirements:
 * For factor of three print Fizz instead of the number
 * For factor of five print Buzz instead of the number
 * For numbers which are factors of both three and five print FizzBuzz instead of the number
 */
import java.util.LinkedHashMap;
import java.util.Map;


public class FizzBuzz {

    public Map<Integer, String> factors = new LinkedHashMap<Integer, String>();

    public String say(int number) {

        factors.put(15, "FizzBuzz");
        factors.put(3, "Fizz");
        factors.put(5, "Buzz");

        for (int i : factors.keySet()) {
            System.out.println(i);
            if(number % i == 0) return factors.get(i);
        }

        return String.valueOf(number);
    }
}
