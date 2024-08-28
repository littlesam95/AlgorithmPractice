#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[101][101];
int island[101][101];
bool visited[101][101];
vector<pair<int, int> > vec;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int island_size = 1;
int answer = INT_MAX;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	int island_num = island[y][x];
	visited[y][x] = true;
	q.push(make_pair(make_pair(y, x), make_pair(0, 0)));

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_bridge = q.front().second.first;
		q.pop();

		if ((arr[now_y][now_x]) && ((now_y != y) || (now_x != x)) && (island[now_y][now_x] != island_num)) {
			answer = min(answer, now_bridge - 1);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= N)) {
				if ((!visited[next_y][next_x]) && (island[next_y][next_x] != island_num)) {
					visited[next_y][next_x] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_bridge + 1, 0)));
				}
			}
		}
	};
}

void find_island(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	island[y][x] = island_size;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= N)) {
				if ((!visited[next_y][next_x]) && (arr[next_y][next_x])) {
					visited[next_y][next_x] = true;
					island[next_y][next_x] = island_size;
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

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < N; j++) {
			if ((arr[i][j]) && (!visited[i][j])) {
				find_island(i, j);
				island_size++;
			}
		}
	}
	island_size--; 

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) {
				int size_ocean = 0;
				if ((i - 1 > 0) && (!arr[i - 1][j])) {
					size_ocean++;
				}
				if ((i + 1 <= N) && (!arr[i + 1][j])) {
					size_ocean++;
				}
				if ((j - 1 > 0) && (!arr[i][j - 1])) {
					size_ocean++;
				}
				if ((j + 1 <= N) && (!arr[i][j + 1])) {
					size_ocean++;
				}
				if (size_ocean >= 1) {
					vec.push_back(make_pair(i, j));
				}
			}
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		init();
		bfs(vec[i].first, vec[i].second);
	}

	cout << answer << "\n";

	return 0;
}