#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
string str;
int dp[2550][2550] = { 0, };
int dp2[2550] = { 0, };
int answer = 0;

void init() {
	for (int i = 0; i < 2550; i++) {
		dp2[i] = INT_MAX;
		for (int j = 0; j < 2550; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int S, int E) {
	if (S >= E) {
		return 1;
	}
	if (dp[S][E] != -1) {
		return dp[S][E];
	}
	if (str[S] != str[E]) {
		dp[S][E] = 0;
	}
	else {
		dp[S][E] = dfs(S + 1, E - 1);
	}

	return dp[S][E];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> str;
	int len = str.size();
	dp2[0] = 0;
	for (int i = 1; i <= len; i++) {
		dp2[i] = dp2[i - 1] + 1;
		for (int j = 1; j < i; j++) {
			if (!dfs(j - 1, i - 1)) {
				continue;
			}
			dp2[i] = min(dp2[i], dp2[j - 1] + 1);
		}
	}
	cout << dp2[len] << "\n";

	return 0;
}