package ProCodeSmellRemoved;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<String> result = new ArrayList<>();

        String name = "Fahad";
        name = String.join("", name);
        result.add(name);

        result.add("ahmed");
        for(String ls: result) {
            System.out.print(ls);
        }
    }
}
