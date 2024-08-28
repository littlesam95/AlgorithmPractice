#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int dp[30][30];

void init() {
	for (int i = 0; i < 30; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
		dp[i][i] = 1;
	}
	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 29; j++) {
			dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
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
		int N, M;
		cin >> N >> M;
		cout << dp[M][N] << "\n";;
	};

	return 0;
}