#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    double price;
    int stock;

public:
    Book(const string& t, const string& a, const string& p, double pr, int s)
        : title(t), author(a), publisher(p), price(pr), stock(s) {}

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
    }

    bool match(const string& t, const string& a) const {
        return (title == t && author == a);
    }

    void purchase(int quantity) {
        if (quantity <= stock) {
            cout << "Total cost: " << price * quantity << endl;
            stock -= quantity;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main() {
    Book books[] = {
        Book("C++ Programming", "Bjarne Stroustrup", "Addison-Wesley", 45.99, 10),
        Book("The Art of Computer Programming", "Donald Knuth", "Addison-Wesley", 89.50, 5),
        Book("Clean Code", "Robert C. Martin", "Prentice Hall", 42.99, 8)
    };

    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter author name: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (Book& book : books) {
        if (book.match(searchTitle, searchAuthor)) {
            found = true;
            book.display();

            int copies;
            cout << "Enter number of copies required: ";
            cin >> copies;

            book.purchase(copies);
            break;
        }
    }

    if (!found) {
        cout << "Book not available." << endl;
    }

    return 0;
}
