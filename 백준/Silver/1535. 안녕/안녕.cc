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
#define MAX_J 101
#define LL long long
#define INF 1e9

using namespace std;
int N;
int L[MAX_N], J[MAX_N];
int DP[MAX_N][MAX_J];
int Answer = 0;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> J[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 100; j >= 0; j--) {
			if (j - L[i] >= 1) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - L[i]] + J[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
			Answer = max(Answer, DP[i][j]);
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