#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int arr[501][501] = { 0, };
bool visited[501][501] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int res = 0; // 그림의 개수
int big = 0; // 가장 넓은 그림의 넓이

void bfs(int y, int x, int count) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	res++;
	count++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < n) && (nextX >= 0) && (nextX < m)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 1)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
					count++;
				}
			}
		}
	};

	if (big < count) {
		big = count;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 1)) {
				bfs(i, j, 0);
			}
		}
	}

	cout << res << "\n";
	cout << big << "\n";

	return 0;
}