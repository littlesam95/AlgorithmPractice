#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 301
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
int MAP[MAX][MAX];
int Sum[MAX][MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	cin >> K;
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Sum[i][j] = Sum[i][j - 1] + MAP[i][j];
		}
	}
}

void Find_Answer() {
	while (K--) {
		int Answer = 0;
		int I, J, X, Y;
		cin >> I >> J >> X >> Y;
		for (int i = I; i <= X; i++) {
			Answer += (Sum[i][Y] - Sum[i][J - 1]);
		}
		cout << Answer << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}