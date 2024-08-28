#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 9876543210

using namespace std;
int N, M;
int dist[501][501];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if ((dist[i][k] == 1) && (dist[k][j] == 1)) {
					dist[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		bool flag = true;
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			if ((dist[i][j] == 0) && (dist[j][i] == 0)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}