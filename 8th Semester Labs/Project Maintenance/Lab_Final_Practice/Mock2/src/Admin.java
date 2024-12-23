

public class Admin extends LibraryMember {
    public Admin(String name, int memberId) {
        super(name, memberId);
    }

    public void addBook(Book book, Library library) {
        library.addBook(book);
    }

    public void removeBook(Book book, Library library) {
        library.removeBook(book);
    }

    @Override
    public String toString() {
        return super.toString() + " (Admin)";
    }
}
