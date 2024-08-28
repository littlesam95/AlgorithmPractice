#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, L, R;
long dp[101][101][101] = { 0, };

void init() {
	dp[1][1][1] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = 1; k <= i; k++) {
				if ((i == j) && (k == 1)) {
					dp[i][j][k] = 1;
				}
				else if ((i == k) && (j == 1)) {
					dp[i][j][k] = 1;
				}
				else {
					dp[i][j][k] = ((dp[i - 1][j][k] * (i - 2) % 1000000007) + (dp[i - 1][j - 1][k] % 1000000007) + (dp[i - 1][j][k - 1] % 1000000007)) % 1000000007;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> L >> R;
	cout << dp[N][L][R] % 1000000007 << "\n";

	return 0;
}