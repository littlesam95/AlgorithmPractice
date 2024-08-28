#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int n, m;
int arr[60][60];
int moveY[4] = { 0,-1,0,1 };
int moveX[4] = { -1,0,1,0 };
bool visited[60][60];
int room = 0;
int big = 0;
int new_big = 0;

void init() {
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	int now_room = 0;
	int now_big_room = 0;
	visited[y][x] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	now_room++;

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < m) && (next_x >= 0) && (next_x < n)) {
				if (!(arr[now_y][now_x] & (1 << i))) {
					if (!visited[next_y][next_x]) {
						visited[next_y][next_x] = true;
						now_room++;
						q.push(make_pair(next_y, next_x));
					}
				}
			}
		}
	};

	big = max(big, now_room);
	new_big = max(new_big, now_room);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
				room++;
			}
		}
	}

	cout << room << "\n";
	cout << big << "\n";

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (arr[i][j] & (1 << k)) {
					init();
					arr[i][j] -= (1 << k);
					for (int a = 0; a < m; a++) {
						for (int b = 0; b < n; b++) {
							if (!visited[a][b]) {
								bfs(a, b);
							}
						}
					}
					arr[i][j] |= (1 << k);
				}
			}
		}
	}

	cout << new_big << "\n";

	return 0;
}