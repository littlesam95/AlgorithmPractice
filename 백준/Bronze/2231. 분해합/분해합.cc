#include <iostream>

using namespace std;

int main() {
	int N;
	do {
		cin >> N;
	} while ((N < 1) || (N > 1000000));

	int M = N;
	int tmp, size = 0;
	tmp = N;
	for (int i = 0; i < 7; i++) {
		if (tmp > 0) {
			tmp /= 10;
			size++;
		}
		else if (tmp == 0) {
			break;
		}
	}
	bool result = false;
	int tmp1, tmp2;
	for (int i = N - (size * 9); i < N; i++) {
		tmp1 = i, tmp2 = i;
		while (tmp2 > 0) {
			tmp1 += tmp2 % 10;
			tmp2 /= 10;
		};
		if (tmp1 == N) {
			result = true;
			if (M > i) {
				M = i;
				break;
			}
		}
	}

	if (result) {
		cout << M;
	}
	else if (!result) {
		M = 0;
		cout << M;
	}

	return 0;
}