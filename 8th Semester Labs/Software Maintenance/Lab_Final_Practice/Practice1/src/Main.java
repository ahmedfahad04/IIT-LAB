import OOP.Circle;
import OOP.Shape;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Main {
    public static void main(String[] args) {

        ///  - Basic Variable

        String data = "This is a sample test. You have to count the  words and print the frequencies beside.";
        String[] words = data.split("\\s+");
        HashMap<String, Integer> wordFreq = new HashMap<>();

        for (String word: words) {
            word = word.toLowerCase().replaceAll("[^a-zA-Z]", "");
            if(!word.isEmpty()) {
                wordFreq.put(word, wordFreq.getOrDefault(word, 0)+1);
            }
        }

        // sort elements
        List<Map.Entry<String, Integer>> sortedList = new ArrayList<>(wordFreq.entrySet());
        sortedList.sort((ent1, ent2) -> ent1.getValue().compareTo(ent2.getValue()));

        // count word frequencies
        System.out.println("Word Frequencies...");
        for (Map.Entry<String, Integer> entry: sortedList) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        /// - OOP basics

        Book book1 = new Book(null, null, 500.5);
        book1.showDetails();

        ///  - Try catch block

        try {
            int result = 10/0;
            System.out.println("Its wrong bro");
        } catch (ArithmeticException e) {
            System.out.println("Error: Can't divide by 0\n" + e.fillInStackTrace());
        }


        try {
            ArrayList<Integer> heights = new ArrayList<>();
            Collections.addAll(heights, 150,160,144,122,155);
            System.out.println("Show height of the 5th person: " + heights.get(4));
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: \n" + e.fillInStackTrace());
        }

        /// - read files

        try (FileWriter writer = new FileWriter("test.txt")) {
            writer.write("Hello from basic java 2");
            System.out.println("File writen successfully!");
        } catch (IOException e) {
            System.out.println("An error occurred " + e.getMessage());
        }

        /// - Inheritance
        Shape shape1 = new Circle(5);
        System.out.println("Circle area is: " + shape1.calculateArea(5));
    }
}

class Book {
    String title = "Ikigai";
    String author = "Hiroshima Nagakami";
    double price = 155.5;

    // for optional param we can use null or Builder pattern or varargs

    /*
    *  public Book(String... params) {
        if (params.length > 0) this.title = params[0];
        if (params.length > 1) this.author = params[1];
        if (params.length > 2) this.price = Double.parseDouble(params[2]);
    }
    * */

    public Book (String title, String author, double price) {
        this.title = title != null ? title : this.title;
        this.author = author != null ? author : this.author;
        this.price = price;
    }

    public void showDetails() {
        System.out.println("\n-----------");
        System.out.println("Book: " + title + "\nAuthor: " + author + "\nPrice: " + price);
    }
}