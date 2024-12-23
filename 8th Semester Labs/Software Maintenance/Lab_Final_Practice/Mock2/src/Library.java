import java.io.FileWriter;
import java.util.ArrayList;
import java.util.List;

public class Library {
    List<Book> books;

    public Library() {
        books = new ArrayList<>();
    }

    public void addBook(Book book) {
        books.add(book);
        System.out.println("Added book: " + book.getTitle());
    }

    public void removeBook(Book book) {
        if (books.contains(book)) {
            books.remove(book);
            System.out.println("Removed book: " + book.getTitle());
        } else {
            System.out.println("Book not found in library.");
        }
    }

    public void searchBooks(String searchTerm) {
        boolean found = false;
        for (Book book : books) {
            if (book.getTitle().contains(searchTerm) || book.getAuthor().contains(searchTerm)) {
                System.out.println(book);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No books found with the term: " + searchTerm);
        }
    }

    public void displayAvailableBooks() {
        for (Book book : books) {
            if (!book.isBorrowed()) {
                System.out.println(book);
            }
        }
    }

    public void displayAllBooks() {
        for (Book book : books) {
            System.out.println(book);
        }
    }

    public void saveLibraryStatus() {
        for (Book book : books) {
            System.out.println(book);
        }

        try (FileWriter writer = new FileWriter("library_status.txt")) {
            for (Book book : books) {
                writer.write(book.toString() + "\n");
            }
            System.out.println("Library status saved to library_status.txt");
        } catch (Exception e) {
            System.out.println("Error saving library status: " + e.getMessage());
        }
    }

    public void loadLibraryStatus() {
        try {
            String[] lines = new String[books.size()];
            FileWriter writer = new FileWriter("library_status.txt");
            for (int i = 0; i < books.size(); i++) {
                lines[i] = books.get(i).toString();
            }
            writer.write(String.join("\n", lines));
            writer.close();
            System.out.println("Library status loaded from library_status.txt");
        } catch (Exception e) {
            System.out.println("Error loading library status: " + e.getMessage());
        }
    }
}
