#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int w, h;
int arr[51][51];
bool visited[51][51] = { false, };
int moveX[8] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int moveY[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x, int&island) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < h) && (nextX >= 0) && (nextX < w)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 1)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}

			}
		}
	};
	island++;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> w >> h;
		if ((w == 0) && (h == 0)) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		int island = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if ((!visited[i][j]) && (arr[i][j] == 1)) {
					bfs(i, j, island);
				}
			}
		}

		cout << island << "\n";
	};

	return 0;
}