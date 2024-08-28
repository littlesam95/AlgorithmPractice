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
bool Row[MAX][MAX];
bool Col[MAX][MAX];
bool Square[MAX][MAX];

void dfs(int depth) {
	int Y = depth / MAX;
	int X = depth % MAX;
	if (depth == MAX * MAX) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
		exit(0);
	}
	if (arr[Y][X] == 0) {
		for (int i = 1; i <= MAX; i++) {
			if ((!Row[Y][i]) && (!Col[X][i]) && (!Square[(Y / 3) * 3 + (X / 3)][i])) {
				Row[Y][i] = true;
				Col[X][i] = true;
				Square[(Y / 3) * 3 + (X / 3)][i] = true;
				arr[Y][X] = i;
				dfs(depth + 1);
				arr[Y][X] = 0;
				Row[Y][i] = false;
				Col[X][i] = false;
				Square[(Y / 3) * 3 + (X / 3)][i] = false;
			}
		}
	}
	else {
		dfs(depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < MAX; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < S.size(); j++) {
			arr[i][j] = S[j] - '0';
			if (arr[i][j] != 0) {
				Row[i][arr[i][j]] = true;
				Col[j][arr[i][j]] = true;
				Square[(i / 3) * 3 + (j / 3)][arr[i][j]] = true;
			}
		}
	}
	dfs(0);

	return 0;
}