#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 100001

using namespace std;
int T, N;
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
	cin >> T;
	while (T--) {
		cin >> N;
		int newN = N;
		for (int i = 2; i <= N; i++) {
			if (newN == 0) {
				break;
			}
			if (DP[i] == 0) {
				continue;
			}
			int cnt = 0;
			while (1) {
				if (newN % i == 0) {
					newN /= i;
					cnt++;
				}
				else {
					break;
				}
			};
			if (cnt > 0) {
				cout << i << " " << cnt << "\n";
			}
		}
	};

	return 0;
}