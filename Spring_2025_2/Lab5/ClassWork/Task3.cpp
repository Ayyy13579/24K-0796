#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    string isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << endl;
    }
};

class Catalog {
private:
    Book** books;
    int capacity;
    int count;

public:
    Catalog(int size = 100) : capacity(size), count(0) {
        books = new Book*[capacity];
    }

    ~Catalog() {
        delete[] books;
    }

    void addBook(Book* book) {
        if (count < capacity) {
            books[count++] = book;
        } else {
            cout << "Catalog is full." << endl;
        }
    }

    Book* findBookByISBN(const string& isbn) {
        for (int i = 0; i < count; i++) {
            if (books[i]->isbn == isbn) {
                return books[i];
            }
        }
        return nullptr;
    }
};

class Library {
private:
    Catalog catalog;
    Book** books;
    int bookCapacity;
    int bookCount;

public:
    Library(int size = 100) : catalog(size), bookCapacity(size), bookCount(0) {
        books = new Book*[bookCapacity];
    }

    ~Library() {
        delete[] books;
    }

    void addBook(Book* book) {
        if (bookCount < bookCapacity) {
            books[bookCount++] = book;
            catalog.addBook(book);
        } else {
            cout << "Library is full." << endl;
        }
    }

    void findAndDisplayBook(const string& isbn) {
        Book* book = catalog.findBookByISBN(isbn);
        if (book) {
            book->display();
        } else {
            cout << "Book not found in this library." << endl;
        }
    }
};

int main() {
    Book* book1 = new Book("ABC", "Dr.Shehzad", "123456789");
    Book* book2 = new Book("1984", "Test", "987654321");

    Library library1;
    Library library2;

    library1.addBook(book1);
    library1.addBook(book2);

    library2.addBook(book1);

    cout << "Library 1:" << endl;
    library1.findAndDisplayBook("123456789");
    library1.findAndDisplayBook("987654321");

    cout << endl << "Library 2:" << endl;
    library2.findAndDisplayBook("123456789");
    library2.findAndDisplayBook("987654321");

    delete book1;
    delete book2;

    return 0;
}
