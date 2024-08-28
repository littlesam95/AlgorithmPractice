#include <iostream>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 1) || (N > 1000000000));

	int K = 1;

	if (N == 1) {
		cout << 1;
	}
	else if (N == 2) {
		cout << 2;
	}
	else if (N > 2) {
		while (1) {
			if ((((3 * K * K) - 3 * K + 2) <= N) && (((3 * K * K) + 3 * K + 2) > N)) {
				K++;
				break;
			}
			else {
				K++;
			}
		};
		cout << K;
	}

	return 0;
}