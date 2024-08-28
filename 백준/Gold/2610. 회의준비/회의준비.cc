#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N, M;
int dist[101][101];
bool visited[101];
vector<int> vec[101];
vector<int> committee[101];
int answer = 0;
vector<int> answer_rep;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = MAX;
			}
		}
	}
}

void bfs_floyd(int x, int idx) {
	queue<int> q;
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		int now_x = q.front();
		q.pop();
		committee[idx].push_back(now_x);

		for (int i = 0; i < vec[now_x].size(); i++) {
			if (!visited[vec[now_x][i]]) {
				visited[vec[now_x][i]] = true;
				q.push(vec[now_x][i]);
			}
		}
	};

	sort(committee[idx].begin(), committee[idx].end());
	int committee_size = committee[idx].size();
	for (int k = 0; k < committee_size; k++) {
		for (int i = 0; i < committee_size; i++) {
			for (int j = 0; j < committee_size; j++) {
				if (i == j) {
					continue;
				}
				if (dist[committee[idx][i]][committee[idx][j]] > dist[committee[idx][i]][committee[idx][k]] + dist[committee[idx][k]][committee[idx][j]]) {
					dist[committee[idx][i]][committee[idx][j]] = dist[committee[idx][i]][committee[idx][k]] + dist[committee[idx][k]][committee[idx][j]];
				}
			}
		}
	}
	int big = MAX;
	int represent = 0;
	for (int i = 0; i < committee_size; i++) {
		int cnt = 0;
		for (int j = 0; j < committee_size; j++) {
			if (cnt < dist[committee[idx][i]][committee[idx][j]]) {
				cnt = dist[committee[idx][i]][committee[idx][j]];
			}
		}
		if (big > cnt) {
			big = cnt;
			represent = committee[idx][i];
		}
	}
	answer_rep.push_back(represent);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	init();
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			bfs_floyd(i, idx);
			answer++;
			idx++;
		}
	}
	cout << answer << "\n";
	sort(answer_rep.begin(), answer_rep.end());
	for (int i = 0; i < answer_rep.size(); i++) {
		cout << answer_rep[i] << "\n";
	}

	return 0;
}