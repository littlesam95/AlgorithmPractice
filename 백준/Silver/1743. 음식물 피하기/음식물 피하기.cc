#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, K;
int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int res = 0;

void bfs(int y, int x, int count) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	count++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 1)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
					count++;
				}
			}
		}
	};

	if (res < count) {
		res = count;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1 - 1][n2 - 1] = 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 1)) {
				bfs(i, j, 0);
			}
		}
	}

	cout << res << "\n";

	return 0;
}