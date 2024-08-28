#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 6600

using namespace std;
int N;
char MAP[MAX][MAX];

void Find_Map(int n, int r, int c) {
	if (n == 3) {
		for (int i = c - 2; i <= c; i++) {
			MAP[r][i] = '*';
		}
		MAP[r + 1][c - 2] = '*';
		MAP[r + 1][c] = '*';
		for (int i = c - 2; i <= c; i++) {
			MAP[r + 2][i] = '*';
		}
		return;
	}
	Find_Map(n / 3, r, c - n / 3 - n / 3);
	Find_Map(n / 3, r + n / 3, c - n / 3 - n / 3);
	Find_Map(n / 3, r + n / 3 + n / 3, c - n / 3 - n / 3);
	Find_Map(n / 3, r, c - n / 3);
	Find_Map(n / 3, r + n / 3 + n / 3, c - n / 3);
	Find_Map(n / 3, r, c);
	Find_Map(n / 3, r + n / 3, c);
	Find_Map(n / 3, r + n / 3 + n / 3, c);
}

void Sort_Map() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < (N * 2); j++) {
			if (MAP[i][j] != '*') {
				MAP[i][j] = ' ';
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	Find_Map(N, 1, N);
	Sort_Map();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}

	return 0;
}