public class Book {
    protected String title;
    protected String author;
    protected boolean isBorrowed;

    public Book(String title, String author) {
        this.title = title;
        this.author = author;
        this.isBorrowed = false;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public boolean isBorrowed() {
        return isBorrowed;
    }

    public void borrow() {
        if (isBorrowed) {
            System.out.println("This book is already borrowed.");
        } else {
            isBorrowed = true;
            System.out.println("You have borrowed: " + title);
        }
    }

    public void returnBook() {
        if (!isBorrowed) {
            System.out.println("This book was not borrowed.");
        } else {
            isBorrowed = false;
            System.out.println("You have returned: " + title);
        }
    }

    @Override
    public String toString() {
        return "Title: " + title + ", Author: " + author + ", Borrowed: " + (isBorrowed ? "Yes" : "No");
    }
}
