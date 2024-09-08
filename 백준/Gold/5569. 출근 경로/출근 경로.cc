#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define MOD 100000

using namespace std;
int W, H;
int dp[MAX][MAX][2][2];
int answer = 0;

void init() {
	for (int i = 2; i <= W; i++) {
		dp[i][1][0][0] = 1;
	}
	for (int i = 2; i <= H; i++) {
		dp[1][i][1][0] = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> W >> H;
	init();
	for (int i = 2; i <= W; i++) {
		for (int j = 2; j <= H; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MOD;
			dp[i][j][0][1] = dp[i - 1][j][1][0] % MOD;
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
			dp[i][j][1][1] = dp[i][j - 1][0][0] % MOD;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			answer += dp[W][H][i][j];
		}
	}
	cout << answer % MOD << "\n";

	return 0;
}