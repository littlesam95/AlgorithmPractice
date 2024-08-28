#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_I 51
#define MAX_W 51
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, I, W;
vector<pair<int, int> > Items;
int DP[MAX_I][MAX_W];
int Answer;

void init() {
	Items.clear();
	for (int i = 0; i < MAX_I; i++) {
		for (int j = 0; j < MAX_W; j++) {
			DP[i][j] = 0;
		}
	}
	Answer = 0;
}

void settings() {
	for (int i = 1; i <= I; i++) {
		int V = Items[i - 1].first;
		int C = Items[i - 1].second;
		for (int j = 0; j <= W; j++) {
			if ((j - C) >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - C] + V);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= W; i++) {
		Answer = max(Answer, DP[I][i]);
	}
}

void find_Answer() {
	cout << Answer << "\n";
}

void input() {
	cin >> N;
	while (N--) {
		init();
		cin >> I >> W;
		Items.resize(I);
		for (int i = 0; i < I; i++) {
			cin >> Items[i].first >> Items[i].second;
		}
		settings();
		find_Answer();
	};
}

int main() {
	FASTIO
	input();

	return 0;
}