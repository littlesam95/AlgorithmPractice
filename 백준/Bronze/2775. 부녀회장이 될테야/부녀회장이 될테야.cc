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
	int T;
	cin >> T;
	int k, n;
	int*arr = new int[T];
	int*sum = new int[T];
	for (int i = 0; i < T; i++) {
		cin >> k;
		if ((k < 1) || (k > 14)) {
			exit(0);
		}
		cin >> n;
		if ((n < 1) || (n > 14)) {
			exit(0);
		}
		sum[i] = A(k, n);
	}
	for (int i = 0; i < T; i++) {
		cout << sum[i] << endl;
	}

	return 0;
}