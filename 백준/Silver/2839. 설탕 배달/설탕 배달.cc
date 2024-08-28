#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 3) || (N > 5000));

	int tmp, sum;
	int result = N;
	for (int i = 0; i < (N / 5) + 1; i++) {
		tmp = N;
		sum = 0;
		tmp -= (5 * i);
		if (tmp % 3 == 0) {
			sum = i + (tmp / 3);
			if (result > sum) {
				result = sum;
			}
		}
	}

	if (result != N) {
		cout << result;
	}
	else {
		cout << -1;
	}

	return 0;
}