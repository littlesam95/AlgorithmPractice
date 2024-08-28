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
#define MAX_C 1001
#define LL long long
#define INF 1e9

using namespace std;
int C, N;
int Cost[MAX_N], Client[MAX_N];
int DP[MAX_C * 101];

void Input() {
	cin >> C >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Cost[i] >> Client[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 100000; j++) {
			if (j - Cost[i] >= 0) {
				DP[j] = max(DP[j], DP[j - Cost[i]] + Client[i]);
			}
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= 100000; i++) {
		if (DP[i] >= C) {
			cout << i << "\n";
			break;
		}
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}