#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 81
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
LL DP[MAX];

void init() {
	DP[1] = 1;
	DP[2] = 1;
	for (int i = 3; i < MAX; i++) {
		DP[i] = DP[i - 1] + DP[i - 2];
	}
}

void input() {
	cin >> N;
}

void find_Answer() {
	cout << (DP[N] * 4) + (DP[N - 1] * 2) << "\n";
}

int main() {
	FASTIO
	init();
	input();
	find_Answer();

	return 0;
}