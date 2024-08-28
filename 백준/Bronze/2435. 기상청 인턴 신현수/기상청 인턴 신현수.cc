#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int temper[100];
	for (int i = 0; i < N; i++) {
		cin >> temper[i];
	}

	int sum = -10000;
	for (int i = 0; i < (N - K + 1); i++) {
		int tmp = 0;
		for (int j = i; j < (i + K); j++) {
			tmp += temper[j];
		}
		if (sum < tmp) {
			sum = tmp;
		}
	}

	cout << sum;

	return 0;
}