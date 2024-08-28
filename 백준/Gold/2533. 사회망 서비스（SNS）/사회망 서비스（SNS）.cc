#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 1000001

using namespace std;
int N;
vector<int> vec[MAX_NODE];
vector<int> dirNode[MAX_NODE];
bool visited[MAX_NODE];
int dp[MAX_NODE][2];

void init() {
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
}

int early_adaptor(int S, bool ea) {
	if (dp[S][ea] != -1) {
		return dp[S][ea];
	}

	if (ea) {
		dp[S][ea] = 1;
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][ea] += min(early_adaptor(dirNode[S][i], true), early_adaptor(dirNode[S][i], false));
		}
	}
	else {
		dp[S][ea] = 0;
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][ea] += early_adaptor(dirNode[S][i], true);
		}
	}

	return dp[S][ea];
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

	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	init();
	dfs(1);

	cout << min(early_adaptor(1, true), early_adaptor(1, false)) << "\n";

	return 0;
}