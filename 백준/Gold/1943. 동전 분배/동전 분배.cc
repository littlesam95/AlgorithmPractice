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
#define MAX_N 101
#define MAX_M 50001
#define LL long long
#define INF 1e9

using namespace std;
int N;
pair<int, int> Coin[MAX_N];
int DP[MAX_M];
vector<int> Answer;

void Init() {
	for (int i = 0; i < MAX_M; i++) {
		DP[i] = 0;
	}
	DP[0] = 1;
}

void Settings(int Sum) {
	if (Sum % 2 == 1) {
		Answer.push_back(0);
		return;
	}
	int Half = Sum / 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 50000; j >= 0; j--) {
			if (j - Coin[i].first >= 0) {
				if (DP[j - Coin[i].first] == 1) {
					for (int k = 0; k < Coin[i].second; k++) {
						if (j + Coin[i].first * k < MAX_M) {
							DP[j + Coin[i].first * k] = 1;
						}
					}
				}
			}
		}
	}
	if (DP[Half] == 1) {
		Answer.push_back(1);
		return;
	}
	Answer.push_back(0);
}

void Find_Answer() {
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i] << "\n";
	}
}

void Input() {
	for (int i = 0; i < 3; i++) {
		Init();
		cin >> N;
		int Sum = 0;
		for (int j = 1; j <= N; j++) {
			cin >> Coin[j].first >> Coin[j].second;
			Sum += (Coin[j].first * Coin[j].second);
		}
		Settings(Sum);
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	return 0;
}