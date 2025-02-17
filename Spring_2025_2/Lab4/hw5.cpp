#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class MenuItem {
public:
    string name;
    string type;
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string itemName, string itemType, double itemPrice) {
        menu.push_back(MenuItem(itemName, itemType, itemPrice));
    }

    void addOrder(string itemName) {
        bool itemFound = false;
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                itemFound = true;
                break;
            }
        }
        if (!itemFound) {
            cout << "This item is currently unavailable" << endl;
        }
    }

    void fulfillOrder() {
        if (!orders.empty()) {
            cout << "The " << orders.front() << " is ready" << endl;
            orders.erase(orders.begin()); // Remove the first item from the orders
        } else {
            cout << "All orders have been fulfilled" << endl;
        }
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = numeric_limits<double>::max();
        string cheapestName = "";

        for (const auto& item : menu) {
            if (item.price < minPrice) {
                minPrice = item.price;
                cheapestName = item.name;
            }
        }

        return cheapestName;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    CoffeeShop myShop("Java Delight");

    myShop.addMenuItem("Latte", "drink", 4.50);
    myShop.addMenuItem("Espresso", "drink", 3.00);
    myShop.addMenuItem("Sandwich", "food", 5.00);
    myShop.addMenuItem("Croissant", "food", 2.50);

    myShop.addOrder("Latte");
    myShop.addOrder("Sandwich");
    myShop.addOrder("Cappuccino");

    vector<string> orders = myShop.listOrders();
    cout << "Orders: ";
    for (const auto& order : orders) {
        cout << order << " ";
    }
    cout << endl;

    myShop.fulfillOrder();
    cout << "Total due: $" << myShop.dueAmount() << endl;

    cout << "Cheapest item: " << myShop.cheapestItem() << endl;

    vector<string> drinks = myShop.drinksOnly();
    cout << "Drinks: ";
    for (const auto& drink : drinks) {
        cout << drink << " ";
    }
    cout << endl;

    vector<string> food = myShop.foodOnly();
    cout << "Food: ";
    for (const auto& f : food) {
        cout << f << " ";
    }
    cout << endl;

    return 0;
}
