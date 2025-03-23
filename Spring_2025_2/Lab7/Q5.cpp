#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Media {
    protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
    }

    virtual void checkOut() {
        cout << "Item checked out: " << title << endl;
    }

    virtual void returnItem() {
        cout << "Item returned: " << title << endl;
    }
};

class Book : public Media {
    private:
    string author;
    string ISBN;
    int numberOfPages;
    public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }
};

class DVD : public Media {
    private:
    string director;
    int duration;
    float rating;
    public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, float rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Rating: " << rating << "/10" << endl;
    }
};

class CD : public Media {
    private:
    string artist;
    int numberOfTracks;
    string genre;
    public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Book book1("C++ Programming", "2021-05-10", "B001", "Tech Publishers", "Bjarne Stroustrup", "123-456789", 500);
    DVD dvd1("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD cd1("Thriller", "1982-11-30", "C001", "Epic Records", "Michael Jackson", 9, "Pop");

    cout << "=== Book Details ===" << endl;
    book1.displayInfo();
    book1.checkOut();
    book1.returnItem();

    cout << "=== DVD Details ===" << endl;
    dvd1.displayInfo();
    dvd1.checkOut();
    dvd1.returnItem();

    cout << "=== CD Details ===" << endl;
    cd1.displayInfo();
    cd1.checkOut();
    cd1.returnItem();

    return 0;
}
