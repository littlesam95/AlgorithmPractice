#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long dp[31] = { 0, };

void init() {
	dp[0] = 1;
	for (int i = 1; i < 31; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += (dp[j] * dp[i - j - 1]);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	while (1) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		cout << dp[N] << "\n";
	};

	return 0;
}