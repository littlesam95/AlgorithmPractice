#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int R, C;
char arr[251][251];
bool visited[251][251] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int sheep = 0;
int wolf = 0;

void bfs(int y, int x) {
	int nowSheep = 0;
	int nowWolf = 0;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	if (arr[y][x] == 'k') {
		nowSheep++;
	}
	else if (arr[y][x] == 'v') {
		nowWolf++;
	}

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C) && (!visited[nextY][nextX]) && (arr[nextY][nextX] != '#')) {
				visited[nextY][nextX] = true;
				if (arr[nextY][nextX] == 'k') {
					nowSheep++;
				}
				else if (arr[nextY][nextX] == 'v') {
					nowWolf++;
				}
				q.push(make_pair(nextY, nextX));
			}
		}
	};

	if (nowSheep > nowWolf) {
		wolf -= nowWolf;
	}
	else {
		sheep -= nowSheep;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'k') {
				sheep++;
			}
			else if (arr[i][j] == 'v') {
				wolf++;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((!visited[i][j]) && ((arr[i][j] == 'k') || (arr[i][j] == 'v'))) {
				bfs(i, j);
			}
		}
	}

	cout << sheep << " " << wolf << "\n";

	return 0;
}