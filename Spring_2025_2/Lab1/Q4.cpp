#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float kiloweight, poundsweight;
    cout << "Enter the weight in kilograms: ";
    cin >> kiloweight;
    poundsweight = kiloweight * 2.2;
    cout << fixed << setprecision(2);
    cout << "The weight in pounds is: " << poundsweight << endl;
    cout << "The weight in kilograms is: " << kiloweight << endl;

}