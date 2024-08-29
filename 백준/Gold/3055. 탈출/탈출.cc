#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int R, C;
pair<int, int> start, des;
queue<pair<int, int> > river;
char arr[51][51];
int visited[51][51] = { 0, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int res = -1;

void bfs() {
	queue<pair<int, int> > q;
	q.push(start);
	visited[start.first][start.second] = 1;

	while (!q.empty()) {
		// 물이 차오름
		int nowRiver = river.size();
		for (int i = 0; i < nowRiver; i++) {
			int nowY = river.front().first;
			int nowX = river.front().second;
			river.pop();

			for (int j = 0; j < 4; j++) {
				int nextY = nowY + moveY[j];
				int nextX = nowX + moveX[j];
				if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C)) {
					if (arr[nextY][nextX] == '.') {
						arr[nextY][nextX] = '*';
						river.push(make_pair(nextY, nextX));
					}
				}
			}
		}

		// 고슴도치 이동
		int nowSize = q.size();
		for (int i = 0; i < nowSize; i++) {
			int nowY = q.front().first;
			int nowX = q.front().second;
			q.pop();

			if ((nowY == des.first) && (nowX == des.second)) {
				res = visited[nowY][nowX] - 1;
			}

			for (int j = 0; j < 4; j++) {
				int nextY = nowY + moveY[j];
				int nextX = nowX + moveX[j];
				if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C)) {
					if ((visited[nextY][nextX] == 0) && ((arr[nextY][nextX] == '.') || (arr[nextY][nextX] == 'D'))) {
						visited[nextY][nextX] = visited[nowY][nowX] + 1;
						q.push(make_pair(nextY, nextX));
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				start = make_pair(i, j);
			}
			else if (arr[i][j] == '*') {
				river.push(make_pair(i, j));
			}
			else if (arr[i][j] == 'D') {
				des = make_pair(i, j);
			}
		}
	}

	bfs();

	if (res != -1) {
		cout << res << "\n";
	}
	else {
		cout << "KAKTUS" << "\n";
	}

	return 0;
}