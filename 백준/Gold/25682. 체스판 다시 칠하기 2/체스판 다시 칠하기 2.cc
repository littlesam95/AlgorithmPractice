#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 2001
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K;
char MAP[MAX][MAX];
char White[MAX][MAX];
char Black[MAX][MAX];
int Change_White[MAX][MAX];
int Change_Black[MAX][MAX];
int SumW[MAX][MAX];
int SumB[MAX][MAX];
int Answer = INF;

void init() {
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (i % 2 == 1) {
				if (j % 2 == 1) {
					White[i][j] = 'W';
					Black[i][j] = 'B';
				}
				else {
					White[i][j] = 'B';
					Black[i][j] = 'W';
				}
			}
			else {
				if (j % 2 == 1) {
					White[i][j] = 'B';
					Black[i][j] = 'W';
				}
				else {
					White[i][j] = 'W';
					Black[i][j] = 'B';
				}
			}
		}
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
}

void settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (White[i][j] != MAP[i][j]) {
				Change_White[i][j] = 1;
			}
			if (Black[i][j] != MAP[i][j]) {
				Change_Black[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			SumW[i][j] = Change_White[i][j] + SumW[i - 1][j] + SumW[i][j - 1] - SumW[i - 1][j - 1];
			SumB[i][j] = Change_Black[i][j] + SumB[i - 1][j] + SumB[i][j - 1] - SumB[i - 1][j - 1];
		}
	}

	for (int i = K; i <= N; i++) {
		for (int j = K; j <= M; j++) {
			int NowW = SumW[i][j] - SumW[i - K][j] - SumW[i][j - K] + SumW[i - K][j - K];
			int NowB = SumB[i][j] - SumB[i - K][j] - SumB[i][j - K] + SumB[i - K][j - K];
			int Min = min(NowW, NowB);
			Answer = min(Answer, Min);
		}
	}
}

void find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	init();
	input();
	settings();
	find_Answer();

	return 0;
}