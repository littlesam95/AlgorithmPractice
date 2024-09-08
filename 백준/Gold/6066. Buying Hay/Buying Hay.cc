#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_N 101
#define MAX_H 55555
#define LL long long
#define INF 1e9

using namespace std;
int N, H;
int P[MAX_N], C[MAX_N];
int DP[MAX_N][MAX_H];
int Answer = INF;

void Input() {
	cin >> N >> H;
	for (int i = 1; i <= N; i++) {
		cin >> P[i] >> C[i];
	}
}

void Settings() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < MAX_H; j++) {
			DP[i][j] = INF;
		}
	}
	DP[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < MAX_H; j++) {
			if (j - P[i] >= 0) {
				DP[i][j] = min(DP[i - 1][j], DP[i][j - P[i]] + C[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	for (int i = H; i < MAX_H; i++) {
		Answer = min(Answer, DP[N][i]);
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}