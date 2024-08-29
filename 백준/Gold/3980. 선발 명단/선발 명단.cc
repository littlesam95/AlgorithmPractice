#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 12

using namespace std;
int C;
int arr[MAX][MAX];
bool visited[MAX];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
		for (int j = 0; j < MAX; j++) {
			arr[i][j] = 0;
		}
	}
	answer = 0;
}

void dfs(int X, int res) {
	if (X == MAX) {
		answer = max(answer, res);
		return;
	}
	for (int i = 1; i < MAX; i++) {
		if ((!visited[i]) && (arr[X][i] > 0)) {
			visited[i] = true;
			dfs(X + 1, res + arr[X][i]);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C;
	while (C--) {
		init();
		for (int i = 1; i < MAX; i++) {
			for (int j = 1; j < MAX; j++) {
				cin >> arr[i][j];
			}
		}
		dfs(1, 0);
		cout << answer << "\n";
	};
    
	return 0;
}