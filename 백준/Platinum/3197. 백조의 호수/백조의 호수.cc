#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int R, C;
char arr[1500][1500];
bool visited[1500][1500];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<pair<int, int> > swan;
queue<pair<int, int> > water;
int day = 0;

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (1) {
		queue<pair<int, int> > next_q;
		bool meet = false;

		while (!q.empty()) {
			int now_y = q.front().first;
			int now_x = q.front().second;
			q.pop();

			if ((now_y == swan[1].first) && (now_x == swan[1].second)) {
				meet = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int next_y = now_y + moveY[i];
				int next_x = now_x + moveX[i];
				if ((next_y >= 0) && (next_y < R) && (next_x >= 0) && (next_x < C) && (!visited[next_y][next_x])) {
					visited[next_y][next_x] = true;
					if (arr[next_y][next_x] == 'X') {
						next_q.push(make_pair(next_y, next_x));
						continue;
					}
					q.push(make_pair(next_y, next_x));
				}
			}
		};

		if (meet) {
			break;
		}
		q = next_q;
		int water_size = water.size();
		while (water_size--) {
			int front_y = water.front().first;
			int front_x = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int next_front_y = front_y + moveY[i];
				int next_front_x = front_x + moveX[i];
				if ((next_front_y >= 0) && (next_front_y < R) && (next_front_x >= 0) && (next_front_x < C)) {
					if (arr[next_front_y][next_front_x] == 'X') {
						arr[next_front_y][next_front_x] = '.';
						water.push(make_pair(next_front_y, next_front_x));
					}
				}
			}
		};

		day++;
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			arr[i][j] = tmp[j];
			if (arr[i][j] == 'L') {
				swan.push_back(make_pair(i, j));
			}
			if ((arr[i][j] == '.') || (arr[i][j] == 'L')) {
				water.push(make_pair(i, j));
			}
		}
	}
	bfs(swan[0].first, swan[0].second);
	cout << day << "\n";

	return 0;
}