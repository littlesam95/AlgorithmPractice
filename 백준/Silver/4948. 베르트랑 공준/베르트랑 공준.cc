#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 250001

using namespace std;
int N;
int DP[MAX];

void init() {
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

	init();
	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		int answer = 0;
		for (int i = N + 1; i <= (N * 2); i++) {
			if (DP[i] > 0) {
				answer++;
			}
		}
		cout << answer << "\n";
	};

	return 0;
}