#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
char arr[51][51];
int visited[51][51];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int res = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}
}

void bfs(int y, int x) {
	int count = 1;
	queue<pair<pair<int, int>, int> > q;
	visited[y][x] = count;
	q.push(make_pair(make_pair(y, x), count));

	while (!q.empty()) {
		int nowY = q.front().first.first;
		int nowX = q.front().first.second;
		int nowCount = q.front().second;
		q.pop();

		if (nowCount > res) {
			res = max(nowCount, res);
		}

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M)) {
				if ((visited[nextY][nextX] == 0) && (arr[nextY][nextX] == 'L')) {
					visited[nextY][nextX] = nowCount + 1;
					q.push(make_pair(make_pair(nextY, nextX), nowCount + 1));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			init();
			if (arr[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	cout << (res - 1) << "\n";

	return 0;
}