#include <iostream>
#include <string>
using namespace std;

struct MenuItem {
    string name;
    double price;
    string type;
};

class CoffeeShop {
    private:
    MenuItem menu[4];
    string orders[10];
    int orderCount;
    public:
    const string name;

    CoffeeShop(string shopName, MenuItem menuItems[])
        : name(shopName), orderCount(0) {
        for (int i = 0; i < 4; ++i) {
            menu[i] = menuItems[i];
        }
    }

    void addOrder(string itemName) {
        bool found = false;
        for (int i = 0; i < 4; ++i) {
            if (menu[i].name == itemName) {
                found = true;
                if (orderCount < 10) {
                    orders[orderCount++] = itemName;
                    cout << "Order added: " << itemName << endl;
                } else {
                    cout << "Order list is full!" << endl;
                }
            }
        }
        if (found == false) {
            cout << "Item not found in the menu!" << endl;
        }
    }

    void fulfillOrder() {
        if (orderCount > 0) {
            string order = orders[0];
            for (int i = 0; i < orderCount - 1; ++i) {
                orders[i] = orders[i + 1];
            }
            --orderCount;
            cout << "The " << order << " is ready!" << endl;
        } else {
            cout << "All orders have been fulfilled" << endl;
        }
    }

    void listOrders() {
        if (orderCount == 0) {
            cout << "No orders taken." << endl;
        } else {
            for (int i = 0; i < orderCount; ++i) {
                cout << orders[i] << " " << endl;
            }
        }
    }

    void dueAmount() {
        double total = 0;
        for (int i = 0; i < orderCount; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (menu[j].name == orders[i]) {
                    total += menu[j].price;
                    break;
                }
            }
        }
        cout << "Total due: $" << total << endl;
    }

    void cheapestItem() {
        MenuItem cheapest = menu[0];
        for (int i = 1; i < 4; ++i) {
            if (menu[i].price < cheapest.price) {
                cheapest = menu[i];
            }
        }
        cout << "Cheapest item: " << cheapest.name << endl;
    }

    void drinksOnly() {
        for (int i = 0; i < 4; ++i) {
            if (menu[i].type == "drink") {
                cout << menu[i].name << " " << endl;
            }
        }
    }

    void foodOnly() {
        for (int i = 0; i < 4; ++i) {
            if (menu[i].type == "food") {
                cout << menu[i].name << " " << endl;
            }
        }
    }
};

int main() {
    MenuItem menu[] = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 2.0, "drink"},
        {"Sandwich", 5.0, "food"},
        {"Muffin", 3.0, "food"}
    };

    CoffeeShop shop("Java Haven", menu);

    shop.addOrder("Coffee");
    shop.addOrder("Muffin");
    shop.addOrder("Burger");

    cout << "Orders: "<< endl;
    shop.listOrders();
    
    shop.dueAmount();
    shop.cheapestItem();

    cout << "Drinks: "<< endl;
    shop.drinksOnly();
    
    cout << "Food: "<< endl;
    shop.foodOnly();

    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder();
    
    return 0;
}
