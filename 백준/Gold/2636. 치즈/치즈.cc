#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int h, w;
int arr[101][101];
bool visited[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int hour = 0;
int now_block = 0;
bool all_melt = false;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs() {
	init();
	int answer = 0;
	all_melt = true;
	queue<pair<int, int> > q;
	visited[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < h) && (next_x >= 0) && (next_x < w)) {
				if ((!visited[next_y][next_x]) && (!arr[next_y][next_x])) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
				}
			}
		}
	};

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j]) {
				if (((i - 1 >= 0) && (visited[i - 1][j])) || ((j - 1 >= 0) && (visited[i][j - 1]))
					|| ((i + 1 < h) && (visited[i + 1][j])) || ((j + 1 < w) && (visited[i][j + 1]))) {
					arr[i][j] = 0;
					answer++;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (arr[i][j]) {
				all_melt = false;
				break;
			}
		}
	}

	if (!all_melt) {
		now_block -= answer;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				now_block++;
			}
		}
	}
	while (!all_melt) {
		bfs();
		hour++;
	};

	cout << hour << "\n";
	cout << now_block << "\n";

	return 0;
}