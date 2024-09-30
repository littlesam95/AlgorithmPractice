#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int T, I;
int arr[301][301] = { 0, };
bool visited[301][301] = { false, };
int moveY[8] = { -1,-2,-2,-1,1,2,2,1 };
int moveX[8] = { -2,-1,1,2,2,1,-1,-2 };
int res;

void init() {
	res = 2147483647;
	for (int i = 0; i < I; i++) {
		for (int j = 0; j < I; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	int count = 0;
	queue<pair<pair<int, int>, int> > q;
	visited[y][x] = true;
	q.push(make_pair(make_pair(y, x), count));

	while (!q.empty()) {
		int nowY = q.front().first.first;
		int nowX = q.front().first.second;
		int nowCount = q.front().second;
		q.pop();

		if (arr[nowY][nowX] == 2) {
			if (res > nowCount) {
				res = nowCount;
			}
		}
		else {
			nowCount++;
			for (int i = 0; i < 8; i++) {
				int nextY = nowY + moveY[i];
				int nextX = nowX + moveX[i];
				if ((nextY >= 0) && (nextY < I) && (nextX >= 0) && (nextX < I)) {
					if ((!visited[nextY][nextX])) {
						visited[nextY][nextX] = true;
						q.push(make_pair(make_pair(nextY, nextX), nowCount));
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

	cin >> T;
	while (T--) {
		init();
		cin >> I;
		int n1, n2;
		cin >> n1 >> n2;
		arr[n1][n2] = 1;
		int n3, n4;
		cin >> n3 >> n4;
		arr[n3][n4] = 2;

		bfs(n1, n2);

		cout << res << "\n";
	};

	return 0;
}
