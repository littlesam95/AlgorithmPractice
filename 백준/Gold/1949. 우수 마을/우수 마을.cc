#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_NODE 1000001

using namespace std;
int N;
int arr[10010];
bool visited[10010];
vector<int> vec[10010];
vector<int> dirNode[10010];
int dp[10010][2];
int answer = 0;

void init() {
	for (int i = 0; i < 10010; i++) {
		visited[i] = false;
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
}

int good_town(int S, bool good) {
	if (dp[S][good] != -1) {
		return dp[S][good];
	}
	if (good) {
		dp[S][good] = arr[S];
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][good] += good_town(dirNode[S][i], false);
		}
	}
	else {
		dp[S][good] = 0;
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][good] += max(good_town(dirNode[S][i], false), good_town(dirNode[S][i], true));
		}
	}

	return dp[S][good];
}

void dfs(int S) {
	visited[S] = true;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[vec[S][i]]) {
			dirNode[S].push_back(vec[S][i]);
			dfs(vec[S][i]);
		}
	}
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
	for (int i = 0; i < (N - 1); i++) {
		int l, r;
		cin >> l >> r;
		vec[r].push_back(l);
		vec[l].push_back(r);
	}
	dfs(1);
	cout << max(good_town(1, true), good_town(1, false)) << "\n";

	return 0;
}