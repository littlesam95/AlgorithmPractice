#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N;
int height[101][101] = { 0, };
int high = 0;
bool arr[101][101]; // true는 물에 잠김, false는 물에 잠기지 않음
bool visited[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int res = 0;

void init(int h) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
			if (height[i][j] > h) {
				arr[i][j] = false;
			}
			else {
				arr[i][j] = true;
			}
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N)) {
				if ((!visited[nextY][nextX]) && (!arr[nextY][nextX])) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> height[i][j];
			if (high < height[i][j]) {
				high = height[i][j];
			}
		}
	}

	for (int h = 0; h <= high; h++) {
		init(h);
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if ((!visited[i][j]) && (!arr[i][j])) {
					bfs(i, j);
					count++;
				}
			}
		}
		res = max(res, count);
	}

	cout << res << "\n";

	return 0;
}