#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 301

using namespace std;
int N, M, K;
vector<pair<int, int> > vec[MAX];
int dp[MAX][MAX];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int X, int Y) {
	if (X == N) {
		return 0;
	}
	if (Y == M) {
		return INT_MIN;
	}
	if (dp[X][Y] != -1) {
		return dp[X][Y];
	}
	dp[X][Y] = INT_MIN;
	for (int i = 0; i < vec[X].size(); i++) {
		if (X < vec[X][i].first) {
			dp[X][Y] = max(dp[X][Y], vec[X][i].second + dfs(vec[X][i].first, Y + 1));
		}
	}
	return dp[X][Y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}
	answer = dfs(1, 1);
	if (answer > 0) {
		cout << answer << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}