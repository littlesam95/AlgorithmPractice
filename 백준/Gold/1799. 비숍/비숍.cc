#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 11
#define INF 2e9

using namespace std;
int N;
int arr[MAX][MAX];
int color[MAX][MAX];
int Bishop_arr[MAX][MAX];
int moveY[4] = { -1,-1,1,1 };
int moveX[4] = { -1,1,-1,1 };
int black = 0;
int white = 0;
int answer = 0;

bool Bishop(int Y, int X) {
	for (int i = 0; i < 4; i++) {
		int nextY = Y;
		int nextX = X;
		while (1) {
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
				break;
			}
			if (Bishop_arr[nextY][nextX] == 1) {
				return false;
			}
			nextY += moveY[i];
			nextX += moveX[i];
		}
	}

	return true;
}

void DFS_BLACK(int A, int sum) {
	black = max(black, sum);
	for (int i = A + 1; i < (N * N); i++) {
		int Y = i / N;
		int X = i % N;
		if ((arr[Y][X] == 0) || (color[Y][X] != 1) || (!Bishop(Y, X))) {
			continue;
		}
		Bishop_arr[Y][X] = 1;
		DFS_BLACK(i, sum + 1);
		Bishop_arr[Y][X] = 0;
	}
}

void DFS_WHITE(int A, int sum) {
	white = max(white, sum);
	for (int i = A + 1; i < (N * N); i++) {
		int Y = i / N;
		int X = i % N;
		if ((arr[Y][X] == 0) || (color[Y][X] != 0) || (!Bishop(Y, X))) {
			continue;
		}
		Bishop_arr[Y][X] = 1;
		DFS_WHITE(i, sum + 1);
		Bishop_arr[Y][X] = 0;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					color[i][j] = 1;
				}
			}
			else {
				if (j % 2 == 1) {
					color[i][j] = 1;
				}
			}
		}
	}
	DFS_BLACK(-1, 0);
	DFS_WHITE(-1, 0);
	answer = black + white;
	cout << answer << "\n";

	return 0;
}