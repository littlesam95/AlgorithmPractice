#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, K;
long long dp[1001][1001] = { 0, };

void init() {
	for (int i = 0; i < 1001; i++) {
		dp[i][0] = 1;
	}
	dp[1][1] = 1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	init();
	for (int i = 2; i <= N; i++) {
		for (int j = 1; (2 * j) <= (i + 1); j++) {
			dp[i][j] = ((dp[i - 2][j - 1] % 1000000003) + (dp[i - 1][j] % 1000000003) % 1000000003);
		}
	}

	cout << (dp[N - 3][K - 1] + dp[N - 1][K]) % 1000000003 << "\n";

	return 0;
}