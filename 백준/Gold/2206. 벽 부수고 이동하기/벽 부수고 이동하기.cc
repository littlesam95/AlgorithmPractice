#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int M, N;
int arr[1001][1001];
bool visited[1001][1001][2];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
int answer = INT_MAX;

int bfs() {
	queue<pair<pair<int, int>, pair<int, int>> > q;
	visited[1][1][1] = true;
	q.push(make_pair(make_pair(1, 1), make_pair(1, 1)));

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_breaking = q.front().second.first;
		int now_count = q.front().second.second;
		q.pop();

		if ((now_y == N) && (now_x == M)) {
			return now_count;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= M)) {
				if ((!arr[next_y][next_x]) && (!visited[next_y][next_x][now_breaking])) {
					visited[next_y][next_x][now_breaking] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_breaking, now_count + 1)));
				}
				else {
					if (now_breaking) {
						visited[next_y][next_x][0] = true;
						q.push(make_pair(make_pair(next_y, next_x), make_pair(0, now_count + 1)));
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
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = stoi(tmp.substr(j - 1, 1));
		}
	}
	cout << bfs() << "\n";

	return 0;
}