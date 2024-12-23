public class EBook extends Book {

    public EBook(String title, String author) {
        super(title, author);
    }

    @Override
    public void borrow() {
        if (isBorrowed) {
            System.out.println("Email sent to borrowers.");
        } else {
            isBorrowed = true;
            System.out.println("You have borrowed: " + title);
        }
    }

    @Override
    public void returnBook() {
        if (!isBorrowed) {
            System.out.println("This book was not borrowed.");
        } else {
            isBorrowed = false;
            System.out.println("You have returned: " + title);
        }
    }
}
