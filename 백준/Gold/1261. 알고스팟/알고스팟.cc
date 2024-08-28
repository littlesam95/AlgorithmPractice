#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
int arr[101][101];
int dist[101][101];
bool visited[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
priority_queue<pair<int, pair<int, int> > > pq;

void dijkstra() {
	pq.push(make_pair(0, make_pair(0, 0)));
	dist[0][0] = 0;
	visited[0][0] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		pq.pop();

		if (dist[now_y][now_x] < now_cost) {
			continue;
		}
		if (visited[now_y][now_x]) {
			continue;
		}
		visited[now_y][now_x] = true;

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if (dist[next_y][next_x] > now_cost + arr[next_y][next_x]) {
					dist[next_y][next_x] = now_cost + arr[next_y][next_x];
					pq.push(make_pair(-dist[next_y][next_x], make_pair(next_y, next_x)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			arr[i][j] = S[j] - '0';
			dist[i][j] = INT_MAX;
		}
	}
	dijkstra();
	cout << dist[N - 1][M - 1] << "\n";

	return 0;
}