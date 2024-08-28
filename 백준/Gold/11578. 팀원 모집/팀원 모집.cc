#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 11
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, O, P;
int Problems[MAX];
int Answer = INF;

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> O;
		for (int j = 0; j < O; j++) {
			cin >> P;
			P--;
			Problems[i] |= (1 << P);
		}
	}
}

void dfs(int Depth, int Sum, int Now, int Count) {
	if (Depth == M) {
		if (Sum == ((int)pow(2, N) - 1)) {
			Answer = min(Answer, Count);
		}
		return;
	}

	dfs(Depth + 1, Sum, Now + 1, Count);
	int NewSum = Sum | Problems[Now];
	dfs(Depth + 1, NewSum, Now + 1, Count + 1);
}

void settings() {
	dfs(0, 0, 0, 0);
}

void find_Answer() {
	if (Answer == INF) {
		cout << "-1\n";
	}
	else {
		cout << Answer << "\n";
	}
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}