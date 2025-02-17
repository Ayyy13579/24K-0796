#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    Invoice(const string& pNumber, const string& pDescription, int qty, double price) {
        partNumber = pNumber;
        partDescription = pDescription;
        quantity = (qty > 0) ? qty : 0;
        pricePerItem = (price > 0.0) ? price : 0.0;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }

    void display() const {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item: " << pricePerItem << endl;
        cout << "Total Invoice Amount: " << getInvoiceAmount() << endl;
    }
};

int main() {
    Invoice item("A123", "Hammer", 5, 19.99);
    item.display();

    Invoice invalidItem("B456", "Screwdriver", -3, -10.5);
    invalidItem.display();

    return 0;
}
