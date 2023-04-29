import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class JavaSyntaxes {

    public static void main(String[] args) {

        // create a list of String
        List<String> names = Arrays.asList("Reflection","Collection","Stream");

        // demonstration of filter method
        List<String> result = names.stream().filter(s->s.startsWith("S")).
                toList();


    }
}
