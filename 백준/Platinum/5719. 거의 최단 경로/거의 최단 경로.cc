#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, S, D;
long long dist[500];
vector<pair<int, long long> > vec[500];
vector<pair<int, long long> > vec2[500];
bool visited[500];
priority_queue<pair<long long, int> > pq;

void init1() {
	for (int i = 0; i < 500; i++) {
		vec[i].clear();
		vec2[i].clear();
		visited[i] = false;
	}
}

void init2() {
	for (int i = 0; i < 500; i++) {
		dist[i] = LLONG_MAX;
	}
	while (!pq.empty()) {
		pq.pop();
	};
}

void dijkstra(int x) {
	init2();
	pq.push(make_pair(0, x));
	dist[x] = 0;

	while (!pq.empty()) {
		long long now_cost = -pq.top().first;
		int now_x = pq.top().second;
		pq.pop();

		if (dist[now_x] < now_cost) {
			continue;
		}

		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			if (vec[now_x][i].second == -1) {
				continue;
			}
			if (dist[next_x] > now_cost + next_cost) {
				dist[next_x] = now_cost + next_cost;
				pq.push(make_pair(-(now_cost + next_cost), next_x));
				vec2[next_x].clear();
				vec2[next_x].push_back(make_pair(now_x, now_cost + next_cost));
			}
			else if (dist[next_x] == now_cost + next_cost) {
				vec2[next_x].push_back(make_pair(now_x, now_cost + next_cost));
			}
		}
	};
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	visited[x] = true;
	while (!q.empty()) {
		int now_x = q.front();
		q.pop();

		for (int i = 0; i < vec2[now_x].size(); i++) {
			int next_x = vec2[now_x][i].first;
			for (int j = 0; j < vec[next_x].size(); j++) {
				if (vec[next_x][j].first == now_x) {
					vec[next_x][j].second = -1;
					if (!visited[next_x]) {
						q.push(next_x);
						visited[next_x] = true;
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init1();
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int U, V, P;
			cin >> U >> V >> P;
			vec[U].push_back(make_pair(V, P));
		}
		dijkstra(S); // 최단 경로 탐색
		bfs(D);// 최단 경로에 이용된 경로 제거
		dijkstra(S);// 다시 최단 경로 탐색
		if (dist[D] == LLONG_MAX) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[D] << "\n";
		}
	};

	return 0;
}