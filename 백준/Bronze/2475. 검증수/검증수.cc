#include <iostream>

using namespace std;

int main() {
	int check[5];
	for (int i = 0; i < 5; i++) {
		cin >> check[i];
		if ((check[i] < 0) || (check[i] > 9)) {
			break;
		}
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += (check[i] * check[i]);
	}
	cout << (sum % 10);

	return 0;
}