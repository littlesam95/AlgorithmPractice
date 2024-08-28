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
#define MAX 201
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int MAP[MAX][MAX];
int Sum[MAX][MAX];
int Answer = -INF;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Sum[i][j] = MAP[i][j] + Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = i; k <= N; k++) {
				for (int l = j; l <= M; l++) {
					int Cur = Sum[k][l] - Sum[k][j - 1] - Sum[i - 1][l] + Sum[i - 1][j - 1];
					Answer = max(Answer, Cur);
				}
			}
		}
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