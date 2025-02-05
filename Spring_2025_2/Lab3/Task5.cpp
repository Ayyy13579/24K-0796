#include <iostream>
using namespace std;


class Book {
    private:
    string name;
    int isbn;
    string author;
    string publisher;
    public:
    void setName(string name){
        this->name = name;
    }
    void setISBN(int isbn){
        this->isbn = isbn;
    }
    void setAuthor(string author){
        this->author = author;
    }
    void setPublisher(string publisher){
        this->publisher = publisher;
    }
    string getName(){
        return name;
    }
    int getISBN(){
        return isbn;
    }
    string getAuthor(){
        return author;
    }
    string getPublisher(){
        return publisher;
    }
    string getBookInfo() {
        string a;
        a = "Book Name: " + name + "\nISBN: " + to_string(isbn) + "\nAuthor: " + author + "\nPublisher: " + publisher;
        return a;
    }
};

int main() {
    char choice;
    int i, isbn;
    string name, author, publisher;
    Book myBook[5];
    do {
        cout << "Do you want to enter book details? (y/n): ";
        cin >> choice;
        if (choice == 'y') {
            cout << "Enter book name: ";
            cin >> name;
            myBook[i].setName(name);
            cout << "Enter ISBN: ";
            cin >> isbn;
            myBook[i].setISBN(isbn);
            cout << "Enter author name: ";
            cin >> author;
            myBook[i].setAuthor(author);
            cout << "Enter publisher name: ";
            cin >> publisher;
            myBook[i].setPublisher(publisher);
            i +=1;
        }
    } while (choice == 'y');
    for (int x = 0; x < i; x++) {
        cout << myBook[x].getBookInfo() << endl;
    }
}