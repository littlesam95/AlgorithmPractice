#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int N, M;
char arr[101][101];
bool visited[101][101] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int powerW = 0;
int powerB = 0;

void bfsW(int y, int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	count++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newY = nowY + moveY[i];
			int newX = nowX + moveX[i];
			if ((newY >= 0) && (newY < M) && (newX >= 0) && (newX < N)) {
				if ((!visited[newY][newX]) && (arr[newY][newX] == 'W')) {
					visited[newY][newX] = true;
					q.push(make_pair(newY, newX));
					count++;
				}
			}
		}
	};

	powerW += (count * count);
}

void bfsB(int y, int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	count++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newY = nowY + moveY[i];
			int newX = nowX + moveX[i];
			if ((newY >= 0) && (newY < M) && (newX >= 0) && (newX < N)) {
				if ((!visited[newY][newX]) && (arr[newY][newX] == 'B')) {
					visited[newY][newX] = true;
					q.push(make_pair(newY, newX));
					count++;
				}
			}
		}
	};

	powerB += (count * count);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 'W')) {
				bfsW(i, j);
			}
			else if ((!visited[i][j]) && (arr[i][j] == 'B')) {
				bfsB(i, j);
			}
		}
	}

	cout << powerW << " " << powerB << "\n";

	return 0;
}