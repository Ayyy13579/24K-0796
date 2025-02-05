#include <iostream>
using namespace std;


class User {
	public:
		int age;
		string name;
};

int main() {
	User me;
	me.name = "Teo";
	me.age = 24;
	cout << "My name is " << me.name << " and I'm " << me.age << " years old.";
}
