#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N;
int arr[MAX];
int dp[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = -1;
	}
}

int dfs(int X) {
	if (X == N + 1) {
		return 0;
	}
	if (dp[X] != -1) {
		return dp[X];
	}
	dp[X] = 0;
	int max_num = -1;
	int min_num = INT_MAX;
	for (int i = X; i <= N; i++) {
		max_num = max(max_num, arr[i]);
		min_num = min(min_num, arr[i]);
		dp[X] = max(dp[X], dfs(i + 1) + max_num - min_num);
	}
	return dp[X];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cout << dfs(1) << "\n";

	return 0;
}