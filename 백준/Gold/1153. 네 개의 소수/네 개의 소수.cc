#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;
int N;
int DP[MAX];

void Era() {
	for (int i = 2; i < MAX; i++) {
		DP[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); i++) {
		DP[i * i] = 0;
	}
	for (int i = 2; i < MAX; i++) {
		if (DP[i] == 0) {
			continue;
		}
		for (int j = i + i; j < MAX; j += i) {
			DP[j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Era();
	cin >> N;
	if (N % 2 == 0) {
		int M = N - 4;
		for (int i = 2; i <= (M / 2); i++) {
			if ((DP[i] != 0) && (DP[M - i] != 0)) {
				cout << 2 << " " << 2 << " " << i << " " << M - i << "\n";
				return 0;
			}
		}
	}
	else {
		int M = N - 5;
		for (int i = 2; i <= (M / 2); i++) {
			if ((DP[i] != 0) && (DP[M - i] != 0)) {
				cout << 2 << " " << 3 << " " << i << " " << M - i << "\n";
				return 0;
			}
		}
	}
	cout << -1 << "\n";

	return 0;
}