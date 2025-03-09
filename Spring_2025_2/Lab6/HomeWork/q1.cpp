#include <iostream>
using namespace std;

class Book {
    private:
    string genre;
    public:
    Book(string g) : genre(g) {}
    ~Book() {}
    string getGenre() {
        return genre;
    }
};

class Book1 : public Book {
    private:
    string title;
    string author;
    public:
    Book1(string g, string a, string t) : Book(g), title(t), author(a) {}
    ~Book1() {}
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << getGenre() << endl;
    }
};

class Book2 : public Book {
    private:
    string title;
    string author;
    public:
    Book2(string g, string a, string t) : Book(g), title(t), author(a) {}
    ~Book2() {}
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << getGenre() << endl;
    }
};

int main() {
    Book1 b1("Fiction", "J.K. Rowling", "Harry Potter");
    Book2 b2("Non-Fiction", "Bill Gates", "The Road Ahead");
    b1.display();
    b2.display();
}