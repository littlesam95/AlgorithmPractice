#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 9

using namespace std;
int arr[MAX][MAX];
bool Row[MAX][MAX]; // 가로 I줄에 J라는 수가 있다면 true, 없다면 false
bool Col[MAX][MAX]; // 세로 I줄에 J라는 수가 있다면 true, 없다면 false
bool Square[MAX][MAX]; // ((I / 3) * 3 + (J / 3))번째 3X3 정사각형에 K라는 수가 있다면 true, 없다면 false

void dfs(int order) {
	if (order == MAX * MAX) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int Y = order / MAX;
	int X = order % MAX;
	if (arr[Y][X] == 0) {
		for (int i = 1; i <= MAX; i++) {
			if ((!Row[Y][i]) && (!Col[X][i]) && (!Square[(Y / 3) * 3 + (X / 3)][i])) {
				arr[Y][X] = i;
				Row[Y][i] = true;
				Col[X][i] = true;
				Square[(Y / 3) * 3 + (X / 3)][i] = true;
				dfs(order + 1);
				arr[Y][X] = 0;
				Row[Y][i] = false;
				Col[X][i] = false;
				Square[(Y / 3) * 3 + (X / 3)][i] = false;

			}
		}
	}
	else {
		dfs(order + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				Row[i][arr[i][j]] = true;
				Col[j][arr[i][j]] = true;
				Square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	}
	dfs(0);

	return 0;
}