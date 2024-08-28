#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001

using namespace std;
int N, M, S, E;
vector<pair<int, int> > vec[MAX];
vector<pair<int, int> > vec2[MAX];
int parent_num[MAX];
int dp[MAX];
bool visited[MAX];
queue<int> q;
int answer = 0;

void dfs() {
	while (!q.empty()) {
		int now_idx = q.front();
		q.pop();

		for (int i = 0; i < vec[now_idx].size(); i++) {
			int next_idx = vec[now_idx][i].first;
			dp[next_idx] = max(dp[next_idx], dp[now_idx] + vec[now_idx][i].second);
			parent_num[next_idx]--;
			if (parent_num[next_idx] == 0) {
				q.push(next_idx);
			}
		}
	};
}

void bfs(int x) {
	queue<int> q2;
	q2.push(x);
	visited[x] = true;

	while (!q2.empty()) {
		int now_x = q2.front();
		q2.pop();

		for (int i = 0; i < vec2[now_x].size(); i++) {
			int prev_x = vec2[now_x][i].first;
			if (dp[prev_x] == dp[now_x] - vec2[now_x][i].second) {
				answer++;
				if (!visited[prev_x]) {
					visited[prev_x] = true;
					q2.push(prev_x);
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		parent_num[y]++;
		vec[x].push_back(make_pair(y, t));
		vec2[y].push_back(make_pair(x, t));
	}
	cin >> S >> E;
	q.push(S);
	dfs();
	cout << dp[E] << "\n";
	bfs(E);
	cout << answer << "\n";

	return 0;
}