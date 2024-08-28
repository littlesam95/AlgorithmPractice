#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int M, N, K;
int arr[101][101] = { 0, };
bool visited[101][101] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int res[10001] = { 0, };
int index = 0;


void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	res[index]++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < M) && (nextX >= 0) && (nextX < N)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 0)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
					res[index]++;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int n1, n2, n3, n4;
		cin >> n1 >> n2 >> n3 >> n4;
		for (int j = 0; j < (n4 - n2); j++) {
			for (int k = 0; k < (n3 - n1); k++) {
				arr[M - n2 - 1 - j][n3 - 1 - k] = 1;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 0)) {
				bfs(i, j);
				index++;
			}
		}
	}

	cout << index << "\n";
	sort(res, res + index);
	for (int i = 0; i < index; i++) {
		cout << res[i] << " ";
	}

	return 0;
}