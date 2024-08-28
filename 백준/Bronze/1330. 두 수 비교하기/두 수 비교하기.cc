#include <iostream>

using namespace std;

int main() {
	int A, B;
	do {
		cin >> A >> B;
	} while ((A < -10000) || (A > 10000) || (B < -10000) || (B > 10000));

	if (A > B) {
		cout << ">";
	}
	else if (A < B) {
		cout << "<";
	}
	else if (A == B) {
		cout << "==";
	}

	return 0;
}