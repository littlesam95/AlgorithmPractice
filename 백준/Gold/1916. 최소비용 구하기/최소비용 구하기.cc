#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, S, E;
long long dist[20005];
vector<pair<int, long long> > vec[20005]; // pair<도착지 번호, 버스 비용>
priority_queue<pair<int, int> > pq;

void dijkstra() {
	pq.push(make_pair(0, S));
	dist[S] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_vertex = pq.top().second;
		pq.pop();

		if (dist[now_vertex] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_vertex].size(); i++) {
			int next_vertex = vec[now_vertex][i].first;
			int next_cost = vec[now_vertex][i].second;
			if (dist[next_vertex] > now_cost + next_cost) {
				dist[next_vertex] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_vertex], next_vertex));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}
	cin >> S >> E;
	dijkstra();
	cout << dist[E] << "\n";

	return 0;
}