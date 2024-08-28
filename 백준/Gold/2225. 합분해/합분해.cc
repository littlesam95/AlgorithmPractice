#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N, K;
int dp[201][201] = { 0, };
int answer = 0;

void init() {
	for (int i = 1; i <= 200; i++) {
		dp[i][1] = 1;
		dp[1][i] = i;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	init();
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = ((dp[i][j - 1] % 1000000000) + (dp[i - 1][j] % 1000000000)) % 1000000000;
		}
	}

	cout << dp[N][K] % 1000000000 << "\n";

	return 0;
}