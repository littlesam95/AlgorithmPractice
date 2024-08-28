#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 502
#define INF 987654321

using namespace std;
int TC;
int N, M, W;
long long dist[MAX];
vector<pair<pair<int, int>, int> > vec;

void init() {
	for (int i = 1; i < MAX; i++) {
		dist[i] = INF;
	}
	memset(dist, -1, sizeof(dist));
	vec.clear();
}

void Bellman_Ford() {
	dist[1] = 0;
	for (int i = 1; i <= N - 1; i++) { // 
		for (int j = 0; j < vec.size(); j++) {
			int S = vec[j].first.first;
			int E = vec[j].first.second;
			int now_cost = vec[j].second;
			if (dist[S] == INF) {
				continue;
			}
			if (dist[E] > dist[S] + now_cost) {
				dist[E] = dist[S] + now_cost;
			}
		}
	}
	for (int i = 0; i < vec.size(); i++) {
		int S = vec[i].first.first;
		int E = vec[i].first.second;
		int now_cost = vec[i].second;
		if (dist[S] == INF) {
			continue;
		}
		if (dist[E] > dist[S] + now_cost) {
			cout << "YES" << "\n";
			return;
		}
	}
	cout << "NO" << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> TC;
	while (TC--) {
		init();
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec.push_back(make_pair(make_pair(a, b), c));
			vec.push_back(make_pair(make_pair(b, a), c));
		}
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			vec.push_back(make_pair(make_pair(a, b), -c));
		}
		Bellman_Ford();
	};

	return 0;
}