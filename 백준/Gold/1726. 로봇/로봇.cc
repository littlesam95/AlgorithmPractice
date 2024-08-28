#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int M, N;
int arr[101][101];
bool visited[101][101][5];
int moveY[5] = { 0,0,0,1,-1 };
int moveX[5] = { 0,1,-1,0,0 };
int start_y, start_x, start_look;
int end_y, end_x, end_look;

int bfs(int y, int x, int look) {
	queue<pair<pair<int, int>, pair<int, int>> > q;
	visited[y][x][look] = true;
	q.push(make_pair(make_pair(y, x), make_pair(look, 0)));

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_look = q.front().second.first;
		int now_count = q.front().second.second;
		q.pop();

		if ((now_y == end_y) && (now_x == end_x) && (now_look == end_look)) {
			return now_count;
		}

		for (int j = 1; j <= 3; j++) {
			int next_y = now_y + (moveY[now_look] * j);
			int next_x = now_x + (moveX[now_look] * j);
			if (visited[next_y][next_x][now_look]) {
				continue;
			}
			if ((next_y > 0) && (next_y <= M) && (next_x > 0) && (next_x <= N) && (!arr[next_y][next_x])) {
				visited[next_y][next_x][now_look] = true;
				q.push(make_pair(make_pair(next_y, next_x), make_pair(now_look, now_count + 1)));
			}
			else {
				break;
			}
		}

		for (int i = 1; i <= 4; i++) {
			if ((!visited[now_y][now_x][i]) && (now_look != i)) {
				visited[now_y][now_x][i] = true;
				if (((now_look == 1) && (i == 2)) || ((now_look == 2) && (i == 1))
					|| ((now_look == 3) && (i == 4)) || ((now_look == 4) && (i == 3))) {
					q.push(make_pair(make_pair(now_y, now_x), make_pair(i, now_count + 2)));
				}
				else {
					q.push(make_pair(make_pair(now_y, now_x), make_pair(i, now_count + 1)));
				}
			}
		}
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> start_y >> start_x >> start_look;
	cin >> end_y >> end_x >> end_look;
	cout << bfs(start_y, start_x, start_look) << "\n";

	return 0;
}