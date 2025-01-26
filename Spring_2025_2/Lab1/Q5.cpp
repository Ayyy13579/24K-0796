#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string moviename;
    float adulttickets, childtickets, grossamount, donatedamount, totalamount;
    int adultsold, childsold, totalsold;
    cout << "Enter the name of the movie: ";
    cin >> moviename;
    cout << "Enter the number of adult tickets sold: ";
    cin >> adultsold;
    cout << "Enter the number of child tickets sold: ";
    cin >> childsold;
    adulttickets = adultsold * 10;
    childtickets = childsold * 6;
    grossamount = adulttickets + childtickets;
    donatedamount = grossamount * 0.10;
    totalamount = grossamount - donatedamount;
    totalsold = adultsold + childsold;
    cout << "Movie Name: " << moviename << endl;
    cout << "Tickets Sold: " << totalsold << endl;
    cout << "Gross Amount: " << grossamount << endl;
    cout << "Percentage Donated: 10%" << endl;
    cout << "Amount Donated: " << donatedamount << endl;
    cout << "Net Sale: " << totalamount << endl;
}