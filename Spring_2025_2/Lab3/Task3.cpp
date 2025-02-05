#include<iostream>
using namespace std;

class Glass {
	public:
		int LiquidLevel;
		int Drink(int milliliters){
			LiquidLevel = LiquidLevel - milliliters;
		}
		int Refill(){
			LiquidLevel=200;
		}
};

int main() {
	int choice, amount;
	Glass water;
	water.LiquidLevel=200;
	do { 
		cout<<"Do you want to drink? 1 for yes, 0 for no: ";
		cin >> choice;
		if(choice == 1){
			cout << "How much? ";
			cin >> amount;
			water.Drink(amount);
		}
		if (water.LiquidLevel < 100) {
			water.Refill();
		}
		cout << "Current liquid left: " << water.LiquidLevel << "\n";
	} while (choice != 0);
}

