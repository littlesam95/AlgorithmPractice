#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int arr[30][30];
int dp[1 << 21][30];
int answer = 0;

void init() {
	for (int i = 0; i < (1 << 21); i++) {
		for (int j = 0; j < 30; j++) {
			dp[i][j] = 0;
		}
	}
}

int dfs(int working, int person) {
	if (working == ((1 << (N - 1)) - 1)) {
		if (person > N) {
			return 0;
		}
	}

	if (dp[working][person] != 0) {
		return dp[working][person];
	}

	int small = MAX;
	for (int i = 1; i <= N; i++) {
		if ((working & (1 << i))) {
			continue;
		}

		int tmp = working | (1 << i);
		int tmp2 = arr[person][i] + dfs(tmp, person + 1);
		small = min(small, tmp2);
	}

	if (small < MAX) {
		dp[working][person] += small;
	}

	return dp[working][person];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs((1 << 0), 1);

	return 0;
}