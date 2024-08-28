#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
string arr[60];
bool visited[1 << 7][60][60] = { false, };
int start_y, start_x;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

int bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(y, x), make_pair(0, 0)));
	visited[0][y][x] = true;

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_moving = q.front().second.first;
		int now_key = q.front().second.second;
		q.pop();

		if (arr[now_y][now_x] == '1') {
			return now_moving;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (arr[next_y][next_x] != '#') && (!visited[now_key][next_y][next_x])) {
				if ((arr[next_y][next_x] == '.') || (arr[next_y][next_x] == '0') || (arr[next_y][next_x] == '1')) {
					visited[now_key][next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_moving + 1, now_key)));
				}
				else if ((arr[next_y][next_x] >= 'a') && (arr[next_y][next_x] <= 'f')) {
					int tmp = now_key | (1 << (int(arr[next_y][next_x]) - 97));
					if (!visited[tmp][next_y][next_x]) {
						visited[now_key][next_y][next_x] = true;
						visited[tmp][next_y][next_x] = true;
						q.push(make_pair(make_pair(next_y, next_x), make_pair(now_moving + 1, tmp)));
					}
				}
				else if ((arr[next_y][next_x] >= 'A') && (arr[next_y][next_x] <= 'F')) {
					int tmp = int(arr[next_y][next_x]) - 65;
					if ((now_key & (1 << tmp))) {
						visited[now_key][next_y][next_x] = true;
						q.push(make_pair(make_pair(next_y, next_x), make_pair(now_moving + 1, now_key)));
					}
				}
			}

		}
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') {
				start_y = i;
				start_x = j;
			}
		}
	}
	cout << bfs(start_y, start_x) << "\n";

	return 0;
}