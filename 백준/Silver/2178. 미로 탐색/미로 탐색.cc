#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int M, N;
bool check[101][101] = { false, };
int res[101][101] = { 0, };
string arr[101];
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };

void bfs(int a, int b) {
	check[a][b] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + moveX[i];
			int dy = y + moveY[i];
			if ((dx >= 0) && (dx < M) && (dy >= 0) && (dy < N) && (arr[dy][dx] == '1') && (!check[dy][dx]) && (res[dy][dx] == 0)) {
				res[dy][dx] = res[y][x] + 1;
				check[dy][dx] = true;
				q.push(make_pair(dy, dx));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	bfs(0, 0);
	cout << res[N - 1][M - 1] + 1 << "\n";

	return 0;
}