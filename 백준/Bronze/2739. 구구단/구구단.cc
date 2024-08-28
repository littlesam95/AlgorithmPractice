#include <iostream>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 1) || (N > 9));

	for (int i = 1; i <= 9; i++) {
		cout << N << " * " << i << " = " << N * i << endl;
	}

	return 0;
}