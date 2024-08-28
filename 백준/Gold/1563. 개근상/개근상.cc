#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
long long dp[1001][2][3] = { 0, };

void init() {
	dp[1][0][0] = 1;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i <= 1000; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % 1000000;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % 1000000;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init();
	long long answer = (dp[N][0][0] + dp[N][0][1] + dp[N][0][2] + dp[N][1][0] + dp[N][1][1] + dp[N][1][2]) % 1000000;
	cout << answer % 1000000 << "\n";

	return 0;
}