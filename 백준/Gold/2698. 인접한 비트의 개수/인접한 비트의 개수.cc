#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int T;
int dp[101][101][2] = { 0, };

void init() {
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 0; i < 101; i++) {
		for (int j = 2; j < 101; j++) {
			if (i == 0) {
				dp[j][i][1] = dp[j - 1][i][0];
			}
			else {
				dp[j][i][1] = dp[j - 1][i - 1][1] + dp[j - 1][i][0];
			}
			dp[j][i][0] = dp[j - 1][i][0] + dp[j - 1][i][1];
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
		int N, K;
		cin >> N >> K;
		cout << dp[N][K][0] + dp[N][K][1] << "\n";
	};

	return 0;
}