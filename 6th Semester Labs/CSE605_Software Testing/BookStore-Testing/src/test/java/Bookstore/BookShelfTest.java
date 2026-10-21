package Bookstore;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.EmptySource;
import org.junit.jupiter.params.provider.MethodSource;
import org.junit.jupiter.params.provider.ValueSource;

import java.time.LocalDate;
import java.time.Month;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

import static org.junit.jupiter.api.Assertions.*;

class BookShelfTest {

    private BookShelf bookShelf;
    private static List<Book> bookList;

    @BeforeAll
    static void beforeAll() {

        // making new book object
        Book effectiveJava = new Book("Effective Java", "Joshua Bloch", LocalDate.of(2019, Month.MAY, 8));
        Book codeComplete = new Book("Code Complete", "Steve McConnel", LocalDate.of(2019, Month.JUNE, 9));
        Book mythicalManMonth = new Book("The Mythical Man-Month", "Frederick Phillips Brooks",
                LocalDate.of(2019, Month.JANUARY, 2));
        Book cleanCode = new Book("Clean Code", "Robert C. Martin", LocalDate.of(2019, Month.AUGUST, 1));

        // populating the bookList
        bookList = new ArrayList<Book>();
        bookList.add(effectiveJava);
        bookList.add(codeComplete);
        bookList.add(cleanCode);
        bookList.add(mythicalManMonth);
    }

    @BeforeEach
    void beforeEach() {
        bookShelf = new BookShelf(bookList);
    }

    @DisplayName("Testing Method Add Books for Empty Book List")
    @ParameterizedTest
    @EmptySource
    void testAddBookShouldReturnEmptyIfNoBooksAdded(List<Book> expected) {
        int size = bookList.size();
        bookShelf.add(expected);
        assertEquals(size, bookShelf.books().size());
    }

    // NEED TO WHY FAILING...
    @Test
    @DisplayName("Testing Method Add Books for Non Empty Book List and Book List Under Capacity")
    void testAddBookShouldBeAddedIfUnderCapacity() {
        Book effectiveJava = new Book("Effective Java", "Joshua Bloch", LocalDate.of(2019, Month.MAY, 8));
        List<Book> expected = new ArrayList<>();
        expected.add(effectiveJava);

        bookShelf.setCapacity(bookShelf.getCapacity()+ 2);
        bookShelf.add(expected);

        List<Book> originalBookList = bookShelf.books();
        assertEquals(effectiveJava,originalBookList.get(originalBookList.size()-4));

    }

    // WHY NO TEST WERE FOUND??
    @DisplayName("Testing Method Add Books for Not Empty Book List")
    @ParameterizedTest
    @MethodSource("generator")
    void testAddBookShouldReturnTrueIfBooksAdded(List<Book> expected) {
        int size = bookList.size();
        bookShelf.add(expected);
        assertTrue(bookShelf.books().size() == size);
    }

    // and then somewhere in this test class
    private static Stream<Arguments> generator() {
        return Stream.of(Arguments.of(bookList));
    }

}