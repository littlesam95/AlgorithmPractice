#include <iostream>

using namespace std;

int A(int k, int n) {
	if (k == 0) {
		return n;
	}
	if (n == 1) {
		return 1;
	}
	return A(k - 1, n) + A(k, n - 1);
}

int main() {
	int N, M;
	do {
		cin >> N >> M;
	} while ((N < 3) || (N > 100) || (M < 10) || (M > 300000));

	int*arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int result = 0;
	int sum;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M) {
					if (result == 0) {
						result = sum;
					}
					else if (result > 0) {
						if (result < sum) {
							result = sum;
						}
					}
				}
			}
		}
	}

	cout << result;

	return 0;
}