#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Tile {
	int first_num, second_num, tile_idx;
};

int N, M;
Tile arr[512][512];
bool connect[512][512][8];
bool visited[512][512];
int parent[270000];
int moveY[8] = { -1,-1,-1,0,1,1,1,0 };
int moveX[8] = { -1,0,1,1,1,0,-1,-1 };
int max_tile = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j].first_num = -1;
			arr[i][j].second_num = -1;
			visited[i][j] = false;
		}
	}
}

void connect_tile() {
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) { // 홀수번째 줄의 타일인 경우, move[8]에서 0, 1, 3, 5, 6, 7번째 방향에 위치한 타일과 연결되며,
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 8; k++) {
					int next_y = i + moveY[k];
					int next_x = j + moveX[k];
					if ((arr[next_y][next_x].first_num == -1) || (arr[next_y][next_x].second_num == -1)) {
						continue;
					}
					if ((k == 2) || (k == 4)) {
						continue;
					}
					if ((k == 0) || (k == 6) || (k == 7)) {
						if (arr[next_y][next_x].second_num == arr[i][j].first_num) {
							connect[i][j][k] = true;
						}
					}
					if ((k == 1) || (k == 3) || (k == 5)) {
						if (arr[next_y][next_x].first_num == arr[i][j].second_num) {
							connect[i][j][k] = true;
						}
					}
				}
			}
		}
		else if (i % 2 == 0) { // 짝수번째 줄의 타일인 경우, move[8]에서 1, 2, 3, 4, 5, 7번째 방향에 위치한 타일과 연결된다.
			for (int j = 1; j <= N - 1; j++) {
				for (int k = 0; k < 8; k++) {
					int next_y = i + moveY[k];
					int next_x = j + moveX[k];
					if ((arr[next_y][next_x].first_num == -1) || (arr[next_y][next_x].second_num == -1)) {
						continue;
					}
					if ((k == 0) || (k == 6)) {
						continue;
					}
					if ((k == 1) || (k == 5) || (k == 7)) {
						if (arr[next_y][next_x].second_num == arr[i][j].first_num) {
							connect[i][j][k] = true;
						}
					}
					if ((k == 2) || (k == 3) || (k == 4)) {
						if (arr[next_y][next_x].first_num == arr[i][j].second_num) {
							connect[i][j][k] = true;
						}
					}
				}
			}
		}
	}
}

void bfs(int y, int x, int idx) {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(y, x), idx));
	visited[y][x] = true;
	parent[idx] = 0;

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_idx = q.front().second;
		q.pop();

		max_tile = max(max_tile, now_idx);

		for (int i = 0; i < 8; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			int next_idx = arr[next_y][next_x].tile_idx;
			if ((arr[next_y][next_x].first_num == -1) || (arr[next_y][next_x].second_num == -1)) {
				continue;
			}
			if ((connect[now_y][now_x][i]) && (!visited[next_y][next_x])) {
				visited[next_y][next_x] = true;
				parent[next_idx] = now_idx;
				q.push(make_pair(make_pair(next_y, next_x), next_idx));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	int num = 1;
	int even_num = 1;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 1) {
			even_num = 0;
		}
		else if (i % 2 == 0) {
			even_num = 1;
		}
		for (int j = 1; j <= N - even_num; j++) {
			int front_num, back_num;
			cin >> front_num >> back_num;
			Tile t;
			t.first_num = front_num;
			t.second_num = back_num;
			t.tile_idx = num;
			arr[i][j] = t;
			num++;
		}
	}
	connect_tile();
	// 시작점은 첫 줄의 첫 타일(num = 1인 타일의 front_num)
	bfs(1, 1, 1);
	vector<int> vec;
	int tmp = max_tile;
	vec.push_back(tmp);
	while (parent[tmp] != 0) {
		vec.push_back(parent[tmp]);
		tmp = parent[tmp];
	};
	cout << vec.size() << "\n";
	for (int i = vec.size() - 1; i >= 0; i--) {
		cout << vec[i] << " ";
	}
	cout << "\n";

	return 0;
}