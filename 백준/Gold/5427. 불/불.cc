#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int T;
int w, h;
char arr[1001][1001];
bool visited[1001][1001];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
vector<pair<int, int> > fire;
int start_y, start_x;
int hour;

void init() {
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			arr[i][j] = ' ';
			visited[i][j] = false;
		}
	}
	fire.clear();
}

int bfs(int y, int x) {
	int answer = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	queue<pair<int, int> > fires;
	for (int i = 0; i < fire.size(); i++) {
		fires.push(make_pair(fire[i].first, fire[i].second));
	}

	while (!q.empty()) {
		int fire_size = fires.size();
		for (int i = 0; i < fire_size; i++) {
			int now_y = fires.front().first;
			int now_x = fires.front().second;
			fires.pop();

			for (int i = 0; i < 4; i++) {
				int next_y = now_y + moveY[i];
				int next_x = now_x + moveX[i];
				if ((next_y > 0) && (next_y <= h) && (next_x > 0) && (next_x <= w)) {
					if ((arr[next_y][next_x] == '.') || (arr[next_y][next_x] == '@')) {
						arr[next_y][next_x] = '*';
						fires.push(make_pair(next_y, next_x));
					}
				}
			}
		}

		int human_size = q.size();
		for (int i = 0; i < human_size; i++) {
			int now_y = q.front().first;
			int now_x = q.front().second;
			q.pop();

			if ((now_y == 1) || (now_y == h) || (now_x == 1) || (now_x == w)) {
				return answer + 1;
			}

			for (int i = 0; i < 4; i++) {
				int next_y = now_y + moveY[i];
				int next_x = now_x + moveX[i];
				if ((next_y > 0) && (next_y <= h) && (next_x > 0) && (next_x <= w) && (!visited[next_y][next_x])) {
					if (arr[next_y][next_x] == '.') {
						visited[next_y][next_x] = true;
						q.push(make_pair(next_y, next_x));
					}
				}
			}
		}
		answer++;
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> w >> h;
		for (int i = 1; i <= h; i++) {
			string tmp;
			cin >> tmp;
			for (int j = 1; j <= w; j++) {
				arr[i][j] = tmp[j - 1];
				if (arr[i][j] == '@') {
					start_y = i;
					start_x = j;
				}
				else if (arr[i][j] == '*') {
					fire.push_back(make_pair(i, j));
				}
			}
		}

		hour = bfs(start_y, start_x);
		if (hour == -1) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << hour << "\n";
		}
	}

	return 0;
}