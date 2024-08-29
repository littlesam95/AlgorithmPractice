#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M;
int dp[MAX][MAX];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
	answer = 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> dp[i][j];
			}
		}
		if ((N < 2) || (M < 2)) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (dp[i][j] == 1) {
						answer = 1;
					}
				}
			}
		}
		else {
			for (int i = 1; i <= N; i++) {
				if (dp[i][1] == 1) {
					answer = 1;
				}
			}
			for (int i = 1; i <= M; i++) {
				if (dp[1][i] == 1) {
					answer = 1;
				}
			}
			for (int i = 2; i <= N; i++) {
				for (int j = 2; j <= M; j++) {
					if (dp[i][j] == 1) {
						dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
						answer = max(answer, dp[i][j]);
					}
				}
			}
		}
		cout << answer << "\n";
	}

	return 0;
}