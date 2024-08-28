#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M;
int arr[301][301];
int tmp[301][301];
bool visited[301][301];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
int year = 0;
bool division = false;

void init() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
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
				if ((arr[next_y][next_x] > 0) && (!visited[next_y][next_x])) {
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
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] > 0) {
					int melt_count = 0;
					if ((i - 1 > 0) && (!arr[i - 1][j])) {
						melt_count++;
					}
					if ((i + 1 <= N) && (!arr[i + 1][j])) {
						melt_count++;
					}
					if ((j - 1 > 0) && (!arr[i][j - 1])) {
						melt_count++;
					}
					if ((j + 1 <= M) && (!arr[i][j + 1])) {
						melt_count++;
					}
					tmp[i][j] = melt_count;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (tmp[i][j] > 0) {
					arr[i][j] -= tmp[i][j];
					if (arr[i][j] < 0) {
						arr[i][j] = 0;
					}
				}
			}
		}
		year++;
		int ice = 0;
		init();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if ((arr[i][j] > 0) && (!visited[i][j])) {
					bfs(i, j);
					ice++;
				}
			}
		}
		if (ice >= 2) {
			division = true;
			break;
		}
		if (ice == 0) {
			break;
		}
	};

	if (division) {
		cout << year << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}