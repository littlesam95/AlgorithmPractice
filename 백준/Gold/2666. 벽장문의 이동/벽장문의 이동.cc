#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int c1, c2;
vector<int> query;
int dp[21][21][21] = { 0, };

void init() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 21; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int dfs(int count, int c1, int c2) {
	if (count == M) {
		return 0;
	}
	if (dp[count][c1][c2] != -1) {
		return dp[count][c1][c2];
	}

	if (query[count] <= c1) {
		dp[count][c1][c2] = dfs(count + 1, query[count], c2) + (c1 - query[count]);
		return dp[count][c1][c2];
	}
	else if (query[count] > c1 && query[count] <= c2) {
		dp[count][c1][c2] = min(dfs(count + 1, query[count], c2) + (query[count] - c1), dfs(count + 1, c1, query[count]) + (c2 - query[count]));
		return dp[count][c1][c2];
	}
	else if (query[count] > c2) {
		dp[count][c1][c2] = dfs(count + 1, c1, query[count]) + (query[count] - c2);
		return dp[count][c1][c2];
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	cin >> c1 >> c2;
	if (c1 > c2) {
		int tmp = c2;
		c2 = c1;
		c1 = tmp;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n1;
		cin >> n1;
		query.push_back(n1);
	}
	cout << dfs(0, c1, c2) << "\n";

	return 0;
}