#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int sum[101];
int dp[101][101] = { 0, };
int answer = 0;

void init() {
	for (int i = 1; i <= M; i++) {
		dp[0][i] = -32768 * 101;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		sum[i] = num + sum[i - 1];
	}
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 1; k <= i; k++) {
				if (k >= 2) {
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
				}
				else if (k == 1 && j == 1) {
					dp[i][j] = max(dp[i][j], sum[i]);
				}
			}
		}
	}

	cout << dp[N][M] << "\n";

	return 0;
}