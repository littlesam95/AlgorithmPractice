#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 10001

using namespace std;
int N;
char MAP[MAX][MAX];

void Find_Map(int n, int r, int c) {
	if (n == 3) {
		MAP[r][c] = '*';
		MAP[r + 1][c - 1] = '*';
		MAP[r + 1][c + 1] = '*';
		for (int i = c - 2; i <= c + 2; i++) {
			MAP[r + 2][i] = '*';
		}
		return;
	}
	Find_Map(n / 2, r, c);
	Find_Map(n / 2, r + n / 2, c - n / 2);
	Find_Map(n / 2, r + n / 2, c + n / 2);
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
		for (int j = 1; j < (N * 2); j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}

	return 0;
}