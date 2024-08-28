#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define MOD 123456789

using namespace std;
int N, M, K;
string word;
char arr[MAX][MAX];
int dp[MAX][MAX][80];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<pair<int, int> > start_point;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < 80; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int dfs(int Y, int X, int Z) {
	if (Z >= word.size()) {
		return 1;
	}
	if (dp[Y][X][Z] != -1) {
		return dp[Y][X][Z];
	}
	dp[Y][X][Z] = 0;
	for (int i = 0; i < 4; i++) {
		int next_y = Y;
		int next_x = X;
		for (int j = 1; j <= K; j++) {
			next_y += moveY[i];
			next_x += moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if (word[Z] == arr[next_y][next_x]) {
					dp[Y][X][Z] = dp[Y][X][Z] + dfs(next_y, next_x, Z + 1);
				}
			}
		}
	}

	return dp[Y][X][Z];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			arr[i][j] = S[j];
		}
	}
	cin >> word;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == word[0]) {
				start_point.push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 0; i < start_point.size(); i++) {
		answer += dfs(start_point[i].first, start_point[i].second, 1);
	}
	cout << answer << "\n";

	return 0;
}