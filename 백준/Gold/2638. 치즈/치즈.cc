#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M;
int arr[101][101];
bool visited[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
int hour = 0;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= M)) {
				if ((arr[next_y][next_x] == 0) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	while (1) {
		init();
		bfs(1, 1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j]) {
					int melt_count = 0;
					if ((i - 1 > 0) && (!arr[i - 1][j]) && (visited[i - 1][j])) {
						melt_count++;
					}
					if ((i + 1 <= N) && (!arr[i + 1][j]) && (visited[i + 1][j])) {
						melt_count++;
					}
					if ((j - 1 > 0) && (!arr[i][j - 1]) && (visited[i][j - 1])) {
						melt_count++;
					}
					if ((j + 1 <= M) && (!arr[i][j + 1]) && (visited[i][j + 1])) {
						melt_count++;
					}
					if (melt_count >= 2) {
						arr[i][j] = 0;
					}
				}
			}
		}
		hour++; 
		bool all_melt = true;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j]) {
					all_melt = false;
					break;
				}
			}
		}
		if (all_melt) {
			break;
		}
	};
	cout << hour << "\n";

	return 0;
}