#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<int> vec[10001];
int T[10001];
int dp[10001];
int parent_num[10001];
queue<int> q;
int answer = 0;

void dfs() {
	while (!q.empty()) {
		int now_idx = q.front();
		q.pop();

		for (int i = 0; i < vec[now_idx].size(); i++) {
			int next_idx = vec[now_idx][i];
			dp[next_idx] = max(dp[next_idx], dp[now_idx] + T[next_idx]);
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

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> T[i] >> num;
		dp[i] = T[i];
		parent_num[i] = num;
		for (int j = 0; j < num; j++) {
			int p;
			cin >> p;
			vec[p].push_back(i);
		}
	}
	for (int i = 1; i <= N; i++) {// 선행 관계에 있는 작업이 하나도 없는 작업은 queue에 push
		if (parent_num[i] == 0) {
			q.push(i);
		}
	}
	dfs();
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[i]);
	}
	cout << answer << "\n";

	return 0;
}