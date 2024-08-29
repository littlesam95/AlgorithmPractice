#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int R, C;
char arr[10001][501];
bool visited[10001][501] = { false, };
int moveY[3] = { -1,0,1 };
int moveX[3] = { 1,1,1 };
int answer = 0;

bool dfs(int y, int x) {
	visited[y][x] = true;
	if (x == C - 1) {
		answer++;
		return true;
	}
	for (int i = 0; i < 3; i++) {
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];
		if ((nextY < 0) || (nextY >= R) || (visited[nextY][nextX]) || (arr[nextY][nextX] == 'x')) {
			continue;
		}
		if (dfs(nextY, nextX)) {
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		dfs(i, 0);
	}

	cout << answer << "\n";

	return 0;
}