#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1e9

using namespace std;
int Sum = 0;
int Min = INF;

void Input() {
	for (int i = 0; i < 7; i++) {
		int N;
		cin >> N;
		if (N % 2 == 1) {
			Sum += N;
			Min = min(Min, N);
		}
	}
}

void Find_Answer() {
	if (Min == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << Sum << "\n" << Min << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}