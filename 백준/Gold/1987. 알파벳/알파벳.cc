#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 26

using namespace std;
int R, C;
char arr[MAX][MAX];
bool visited[MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void dfs(int Y, int X, int dest) {
	answer = max(answer, dest);
	visited[int(arr[Y][X]) - 65] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = Y + moveY[i];
		int nextX = X + moveX[i];
		if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (!visited[int(arr[nextY][nextX]) - 65])) {
			dfs(nextY, nextX, dest + 1);
		}
	}
	visited[int(arr[Y][X]) - 65] = false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= C; j++) {
			arr[i][j] = S[j - 1];
		}
	}
	dfs(1, 1, 1);
	cout << answer << "\n";

	return 0;
}