#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;
int T, N, K, W;
vector<int> vec[MAX];
int build_time[MAX];
int dp[MAX];
int parent_num[MAX];
queue<int> q;

void init() {
	for (int i = 0; i < MAX; i++) {
		vec[i].clear();
		build_time[i] = 0;
		parent_num[i] = 0;
		dp[i] = 0;
	}
	while (!q.empty()) {
		q.pop();
	};
	N = K = W = 0;
}

void dfs() {
	while (!q.empty()) {
		int now_idx = q.front();
		q.pop();

		for (int i = 0; i < vec[now_idx].size(); i++) {
			int next_idx = vec[now_idx][i];
			dp[next_idx] = max(dp[next_idx], dp[now_idx] + build_time[next_idx]);
			parent_num[next_idx]--;
			if (parent_num[next_idx] == 0) {
				q.push(next_idx);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> build_time[i];
			dp[i] = build_time[i];
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			parent_num[y]++;
			vec[x].push_back(y);
		}
		cin >> W;
		for (int i = 1; i <= N; i++) {
			if (parent_num[i] == 0) {
				q.push(i);
			}
		}
		dfs();
		cout << dp[W] << "\n";
	};

	return 0;
}