import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Library library = new Library();
        Admin admin = new Admin("Alice", 1);
        LibraryMember member = new LibraryMember("Bob", 2);
        LibraryMember member2 = new LibraryMember("Alice", 3);

        // Adding books using admin
        admin.addBook(new Book("Java Programming", "John Doe"), library);
        admin.addBook(new Book("Data Structures", "Jane Smith"), library);

        // Display available books
        System.out.println("\nAvailable Books:");
        library.displayAvailableBooks();

        // Member borrowing books
        member.borrowBook(library.books.get(0));
        member2.borrowBook(library.books.get(0));

        // Searching for a book
        System.out.println("\nSearching for books by title or author:");
        library.searchBooks("Java2");

        // Admin removing a book
        // admin.removeBook(library.books.get(1), library);

        // Display all books after removal
        System.out.println("\nAll Books in Library:");
        library.displayAllBooks();

        scanner.close();
    }
}
