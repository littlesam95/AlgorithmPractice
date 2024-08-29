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
#define MAX_N 21
#define MAX_M 10001
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M;
int Coin[MAX_N];
int DP[MAX_M];

void Init() {
	for (int i = 0; i < MAX_M; i++) {
		DP[i] = 0;
	}
	DP[0] = 1;
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < MAX_M; j++) {
			if (j - Coin[i] >= 0) {
				DP[j] += DP[j - Coin[i]];
			}
		}
	}
}

void Find_Answer() {
	cout << DP[M] << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		Init();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> Coin[i];
		}
		cin >> M;
		Settings();
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	return 0;
}