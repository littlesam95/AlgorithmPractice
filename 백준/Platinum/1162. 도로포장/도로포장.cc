#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, K;
long long dist[10001][21];
vector<pair<long long, long long> > vec[10001];
priority_queue<pair<pair<long long, long long>, long long> > pq;
long long answer = LLONG_MAX;

void init() {
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < 21; j++) {
			dist[i][j] = LLONG_MAX;
		}
	}
}

void dijkstra(int x) {
	init();
	pq.push(make_pair(make_pair(0, x), 0));
	dist[x][0] = 0;

	while (!pq.empty()) {
		long long now_cost = -pq.top().first.first;
		long long now_x = pq.top().first.second;
		long long now_paved = pq.top().second;
		pq.pop();

		if (dist[now_x][now_paved] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			long long next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			if (dist[next_x][now_paved] > now_cost + next_cost) {
				dist[next_x][now_paved] = now_cost + next_cost;
				pq.push(make_pair(make_pair(-dist[next_x][now_paved], next_x), now_paved));
			}
			if ((now_paved < K) && (dist[next_x][now_paved + 1] > now_cost)) {
				dist[next_x][now_paved + 1] = now_cost;
				pq.push(make_pair(make_pair(-dist[next_x][now_paved + 1], next_x), now_paved + 1));
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
		long long n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
		vec[n2].push_back(make_pair(n1, n3));
	}
	dijkstra(1);
	for (int i = 0; i <= K; i++) {
		answer = min(answer, dist[N][i]);
	}
	cout << answer << "\n";

	return 0;
}