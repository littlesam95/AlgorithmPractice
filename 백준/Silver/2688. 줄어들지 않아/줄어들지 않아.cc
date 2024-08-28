#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
long long dp[65][10] = { 0, };

void init() {
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i < 65; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--) {
		int N;
		long long answer = 0;

		cin >> N;
		for (int i = 0; i < 10; i++) {
			answer += dp[N][i];
		}
		cout << answer << "\n";
	};

	return 0;
}