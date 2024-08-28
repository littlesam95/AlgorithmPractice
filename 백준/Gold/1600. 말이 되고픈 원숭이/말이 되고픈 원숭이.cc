#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int K, W, H;
int arr[201][201] = { 0, };
bool visited[201][201][32] = { false, };
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int horseY[8] = { -1,-2,-2,-1,1,2,2,1 };
int horseX[8] = { -2,-1,1,2,2,1,-1,-2 };
int res = -1;

struct info {
	int y;
	int x;
	int count;
	int k;
};

void bfs(int y, int x) {
	int count = 0;
	queue<info> q;
	visited[y][x][0] = true;
	info tmp;
	tmp.y = y;
	tmp.x = x;
	tmp.count = count;
	tmp.k = 0;
	q.push(tmp);

	while (!q.empty()) {
		int nowY = q.front().y;
		int nowX = q.front().x;
		int nowCount = q.front().count;
		int nowK = q.front().k;
		q.pop();

		if ((nowY == H - 1) && (nowX == W - 1)) {
			res = nowCount;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < H) && (nextX >= 0) && (nextX < W)) {
				if ((!visited[nextY][nextX][nowK]) && (arr[nextY][nextX] != 1)) {
					visited[nextY][nextX][nowK] = true;
					info tmp2;
					tmp2.y = nextY;
					tmp2.x = nextX;
					tmp2.count = nowCount + 1;
					tmp2.k = nowK;
					q.push(tmp2);
				}
			}
		}
		if (nowK < K) {
			for (int i = 0; i < 8; i++) {
				int nextY = nowY + horseY[i];
				int nextX = nowX + horseX[i];
				if ((nextY >= 0) && (nextY < H) && (nextX >= 0) && (nextX < W)) {
					if ((!visited[nextY][nextX][nowK + 1]) && (arr[nextY][nextX] != 1)) {
						visited[nextY][nextX][nowK + 1] = true;
						info tmp2;
						tmp2.y = nextY;
						tmp2.x = nextX;
						tmp2.count = nowCount + 1;
						tmp2.k = nowK + 1;
						q.push(tmp2);
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0, 0);

	cout << res << "\n";

	return 0;
}