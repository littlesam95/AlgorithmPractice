#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, K;
priority_queue<long long> dist[1001];
vector<pair<int, long long> > vec[1001];
priority_queue<pair<long long, int> > pq;

void init() {
	for (int i = 0; i < 1001; i++) {
		vec[i].clear();
	}
	while (!pq.empty()) {
		pq.pop();
	};
}

void dijkstra(int x) {
	pq.push(make_pair(0, x));
	dist[x].push(0);

	while (!pq.empty()) {
		long long now_cost = -pq.top().first;
		int now_x = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			if (dist[next_x].size() < K) {
				dist[next_x].push(now_cost + next_cost);
				pq.push(make_pair(-(now_cost + next_cost), next_x));
			}
			else if (dist[next_x].size() == K) {
				if (dist[next_x].top() > now_cost + next_cost) {
					dist[next_x].pop();
					dist[next_x].push(now_cost + next_cost);
					pq.push(make_pair(-(now_cost + next_cost), next_x));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}
	dijkstra(1);
	for (int i = 1; i <= N; i++) {
		if (dist[i].size() != K) {
			cout << -1 << "\n";
		}
		else if (dist[i].size() == K) {
			cout << dist[i].top() << "\n";
		}
	}

	return 0;
}