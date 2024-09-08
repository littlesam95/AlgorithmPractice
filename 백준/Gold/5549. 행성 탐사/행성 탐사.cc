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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K, A, B, C, D;
char MAP[MAX][MAX];
int Sum[3][MAX][MAX];

void Input() {
	cin >> N >> M;
	cin >> K;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = S[j - 1];
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 'J') {
				Sum[0][i][j] = Sum[0][i - 1][j] + Sum[0][i][j - 1] - Sum[0][i - 1][j - 1] + 1;
				Sum[1][i][j] = Sum[1][i - 1][j] + Sum[1][i][j - 1] - Sum[1][i - 1][j - 1];
				Sum[2][i][j] = Sum[2][i - 1][j] + Sum[2][i][j - 1] - Sum[2][i - 1][j - 1];
			}
			else if (MAP[i][j] == 'O') {
				Sum[0][i][j] = Sum[0][i - 1][j] + Sum[0][i][j - 1] - Sum[0][i - 1][j - 1];
				Sum[1][i][j] = Sum[1][i - 1][j] + Sum[1][i][j - 1] - Sum[1][i - 1][j - 1] + 1;
				Sum[2][i][j] = Sum[2][i - 1][j] + Sum[2][i][j - 1] - Sum[2][i - 1][j - 1];
			}
			else if (MAP[i][j] == 'I') {
				Sum[0][i][j] = Sum[0][i - 1][j] + Sum[0][i][j - 1] - Sum[0][i - 1][j - 1];
				Sum[1][i][j] = Sum[1][i - 1][j] + Sum[1][i][j - 1] - Sum[1][i - 1][j - 1];
				Sum[2][i][j] = Sum[2][i - 1][j] + Sum[2][i][j - 1] - Sum[2][i - 1][j - 1] + 1;
			}
		}
	}
}

void Find_Answer() {
	while (K--) {
		cin >> A >> B >> C >> D;
		int First = Sum[0][C][D] - Sum[0][C][B - 1] - Sum[0][A - 1][D] + Sum[0][A - 1][B - 1];
		int Second = Sum[1][C][D] - Sum[1][C][B - 1] - Sum[1][A - 1][D] + Sum[1][A - 1][B - 1];
		int Third = Sum[2][C][D] - Sum[2][C][B - 1] - Sum[2][A - 1][D] + Sum[2][A - 1][B - 1];
		cout << First << " " << Second << " " << Third << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}