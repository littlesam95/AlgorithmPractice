#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_NODE 1000001

using namespace std;
int N;
int arr[10010];
bool visited[10010];
int is_set[10010];
vector<int> vec[10010];
vector<int> dirNode[10010];
vector<int> setNode;
int dp[10010][2];
int answer = 0;

void init() {
	for (int i = 0; i < 10010; i++) {
		visited[i] = false;
		is_set[i] = false;
		for (int j = 0; j < 2; j++) {
			dp[i][j] = -1;
		}
	}
}

void init2() {
	for (int i = 0; i < 10010; i++) {
		visited[i] = false;
	}
}

int most_set(int S, bool good) {
	if (dp[S][good] != -1) {
		return dp[S][good];
	}
	if (good) {
		dp[S][good] = arr[S];
		is_set[S] = true;
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][good] += most_set(dirNode[S][i], false);
		}
	}
	else {
		dp[S][good] = 0;
		is_set[S] = false;
		for (int i = 0; i < dirNode[S].size(); i++) {
			dp[S][good] += max(most_set(dirNode[S][i], false), most_set(dirNode[S][i], true));
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

void select_set(int S, int prev) {
	if ((dp[S][true] > dp[S][false]) && (!visited[prev])) { // 현재 집합을 독립집합에 포함하는 경우가 포함하지 않는 경우보다 더 큰 독립집합을 얻을 수 있다.
		setNode.push_back(S);
		visited[S] = true;
	}

	for (int i = 0; i < vec[S].size(); i++) {
		if (vec[S][i] != prev) {
			select_set(vec[S][i], S);
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
	cout << max(most_set(1, true), most_set(1, false)) << "\n";
	init2();
	select_set(1, 0);
	sort(setNode.begin(), setNode.end());
	for (int i = 0; i < setNode.size(); i++) {
		cout << setNode[i] << " ";
	}
	cout << "\n";

	return 0;
}