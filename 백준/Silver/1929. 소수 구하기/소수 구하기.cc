#include <iostream>
#include <cmath>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int M, N;
	cin >> M >> N;

	int*arr = new int[N + 1];
	for (int i = 2; i < N + 1; i++) {
		arr[i] = i;
	}

	int end = floor(sqrt(N));
	for (int i = 2; i <= end; i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= N; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 2; i < N + 1; i++) {
		if ((M <= i) && (N >= i)) {
			if (arr[i] != 0) {
				cout << i << "\n";
			}
		}
	}

	return 0;
}