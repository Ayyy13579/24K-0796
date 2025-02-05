#include <iostream>
using namespace std;


class Date {
	private:
		int month;
		int day;
		int year;
	public:
		void displayDate() {
			cout << month << "/" << day << "/" << year;
		}
};

int main() {
	Date DateTest;
	DateTest.displayDate();
}
