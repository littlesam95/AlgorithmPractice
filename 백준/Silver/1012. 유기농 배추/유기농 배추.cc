#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int M, N, K;
int arr[60][60];
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };

void init() {
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j < 60; j++) {
			arr[i][j] = 0;
		}
	}
}

void dfs(int a, int b) {
	if (arr[a][b] == 1) {
		arr[a][b] = 0;
		for (int i = 0; i < 4; i++) {
			int x = moveX[i] + a;
			int y = moveY[i] + b;
			if ((x >= 0) && (y >= 0) && (x < M) && (y < N)) {
				dfs(x, y);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, count, T;

	cin >> T;

	while (T--) {
		init();
		count = 0;

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			arr[a][b] = 1;
		}

		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 1) {
					dfs(i, j);
					count++;
				}
			}
		}

		cout << count << "\n";
	};

	return 0;
}