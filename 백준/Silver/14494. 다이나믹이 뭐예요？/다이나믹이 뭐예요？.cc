#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 1001
#define MOD 1000000007
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
LL DP[MAX][MAX];

void init() {
	DP[1][1] = 1;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (DP[i][j] == 0) {
				DP[i][j] = ((DP[i - 1][j] % MOD) + (DP[i][j - 1] % MOD) + (DP[i - 1][j - 1] % MOD)) % MOD;
			}
		}
	}
}

void input() {
	cin >> N >> M;
}

void find_Answer() {
	cout << (DP[N][M] % MOD) << "\n";
}

int main() {
	FASTIO
	init();
	input();
	find_Answer();

	return 0;
}