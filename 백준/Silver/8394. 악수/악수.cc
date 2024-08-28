#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10000001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
int DP[MAX];

void init() {
	DP[0] = 1;
	DP[1] = 1;
	for (int i = 2; i < MAX; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10;
	}
}

void input() {
	cin >> N;
}

void find_Answer() {
	cout << DP[N] << "\n";
}

int main() {
	FASTIO
	init();
	input();
	find_Answer();

	return 0;
}