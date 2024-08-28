#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 201
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int DP[MAX][MAX];
int MAP[MAX][MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		DP[A][B] = C;
		MAP[A][B] = B;
		DP[B][A] = C;
		MAP[B][A] = A;
	}
}

void Settings() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (DP[i][j] > DP[i][k] + DP[k][j]) {
					DP[i][j] = DP[i][k] + DP[k][j];
					MAP[i][j] = MAP[i][k];
				}
			}
		}
	}
}

void Print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 0) {
				cout << "- ";
			}
			else {
				cout << MAP[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

int main() {
	FIRST
	cin >> N >> M;
	init();
	Settings();
	Print();

	return 0;
}