#include <iostream>

using namespace std;

int main() {
	int year;
	do {
		cin >> year;
	} while ((year < 1) || (year > 4000));

	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}