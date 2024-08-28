#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, X;
int dist[1001];
int go_dist[1001];
int re_dist[1001];
vector<pair<int, int> > vec[1001];
priority_queue<pair<int, int> > pq;
int answer = 0;

void init() {
	for (int i = 0; i < 1001; i++) {
		dist[i] = INT_MAX;
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

void dijkstra(int x) {
	init();
	pq.push(make_pair(0, x));
	dist[x] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_x = pq.top().second;
		pq.pop();

		if (dist[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			int next_cost = vec[now_x][i].second;
			if (dist[next_x] > now_cost + next_cost) {
				dist[next_x] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_x], next_x));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
	}
	for (int i = 1; i <= N; i++) {
		if (i == X) {
			dijkstra(X);
			go_dist[i] = 0;
			for (int j = 1; j <= N; j++) {
				if (dist[j] < INT_MAX) {
					re_dist[j] = dist[j];
				}
				else {
					re_dist[j] = -1;
				}
			}
		}
		else {
			dijkstra(i);
			if (dist[X] < INT_MAX) {
				go_dist[i] = dist[X];
			}
			else {
				go_dist[i] = -1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if ((go_dist[i] != -1) && (re_dist[i] != -1)) {
			answer = max(answer, go_dist[i] + re_dist[i]);
		}
	}
	cout << answer << "\n";

	return 0;
}