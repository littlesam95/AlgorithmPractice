#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 501

using namespace std;
int T, N, M;
int last_year[MAX];
bool adj[MAX][MAX];
int parent_num[MAX];
queue<int> q;
vector<int> answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		last_year[i] = 0;
		parent_num[i] = 0;
		for (int j = 0; j < MAX; j++) {
			adj[i][j] = false;
		}
	}
	while (!q.empty()) {
		q.pop();
	};
	answer.clear();
	N = M = 0;
}

void dfs() {
	while (!q.empty()) {
		int now_idx = q.front();
		answer.push_back(now_idx);
		q.pop();

		parent_num[now_idx]--;
		for (int i = 1; i <= N; i++) {
			if (adj[now_idx][i] == 1) {
				parent_num[i]--;
			}
			if (parent_num[i] == 0) {
				q.push(i);
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
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> last_year[i];
		}
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				adj[last_year[i]][last_year[j]] = true;
				parent_num[last_year[j]]++;
			}
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			if (adj[x][y]) {
				adj[x][y] = false;
				adj[y][x] = true;
				parent_num[y]--;
				parent_num[x]++;
			}
			else {
				adj[x][y] = true;
				adj[y][x] = false;
				parent_num[x]--;
				parent_num[y]++;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (parent_num[i] == 0) {
				q.push(i);
			}
		}
		dfs();
		if (answer.size() == N) {
			for (int i = 0; i < N; i++) {
				cout << answer[i] << " ";
			}
			cout << "\n";
		}
		else {
			cout << "IMPOSSIBLE" << "\n";
		}
	};

	return 0;
}