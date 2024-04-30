package bookstore;

import java.time.LocalDate;
import java.time.Year;
import java.util.*;
import java.util.function.Function;

import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.toList;

public class BookShelf {

	private List<Book> books = new ArrayList<>();
	private int capacity;

	public BookShelf() {
		this.capacity = Integer.MAX_VALUE;
	}

	public BookShelf(List<Book> books) {
		this.books = books;
	}

	public BookShelf(int capacity) {
		this.capacity = capacity;
	}

	public void setCapacity(int capacity) {
		this.capacity = capacity;
	}

	public int getCapacity() {
		return capacity;
	}

	public List<Book> books() {
		return Collections.unmodifiableList(books);
	}

	public void add(List<Book> booksToAdd) throws BookShelfCapacityReached {
		for (Book book : booksToAdd) {
			if (books.size() == capacity) {
				throw new BookShelfCapacityReached(
						String.format("BookShelf capacity of %d is reached. You can't add more books.", this.capacity));
			}
			books.add(book);
		}
	}

	public Progress progress() {
		if (books.isEmpty()) {
			return Progress.notStarted();
		}
		int booksRead = Long.valueOf(books.stream().filter(Book::isRead).count()).intValue();
		int booksInProgress = Long.valueOf(books.stream().filter(Book::isProgress).count()).intValue();
		int booksToRead = books.size() - booksRead - booksInProgress;

		int percentageCompleted = booksRead * 100 / books.size();
		int percentageToRead = booksToRead * 100 / books.size();
		int percentageInProgress = booksInProgress * 100 / books.size();

		return new Progress(percentageCompleted, percentageToRead, percentageInProgress);
	}

	public List<Book> findBooksByTitleOrPublishedDateRange(String title, LocalDate firstDate, LocalDate endDate) {
		List<Book> foundBooks = new ArrayList<Book>();
		for (Book book : books) {
			if (book.getPublishedOn().isAfter(firstDate) && book.getPublishedOn().isBefore(endDate)) {
				foundBooks.add(book);
			} else if (book.getTitle().contentEquals(title)) {
				foundBooks.add(book);
			}
		}
		return foundBooks;
	}

	/*
	 * public static void main(String[] args) { BookShelf bookShelf=new
	 * BookShelf(20); Book b1=new Book("b1", "a1", LocalDate.of(2020, 1,1)); Book
	 * b2=new Book("b2", "a2", LocalDate.of(2020, 1,5)); Book b3=new Book("b3",
	 * "a3", LocalDate.of(2020, 3,10)); b1.startedReadingOn(LocalDate.of(2020, 1,
	 * 3)); List<Book> books=new ArrayList<Book>(); books.add(b1); books.add(b2);
	 * books.add(b3); bookShelf.add(books);
	 * System.out.println(bookShelf.progress().inProgress()); }
	 */
}
