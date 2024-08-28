#include <iostream>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 1) || (N > 100));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}