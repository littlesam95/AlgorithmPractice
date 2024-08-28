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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int N;
int L[MAX];
int Sum[MAX][MAX];
int Answer = 0;
pair<int, int> AnswerTwin[MAX];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> L[i];
		for (int j = 1; j <= L[i]; j++) {
			int X;
			cin >> X;
			Sum[i][j] = Sum[i][j - 1] + X;
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		int Big = -INF;
		for (int j = 1; j <= L[i]; j++) {
			for (int k = j; k <= L[i]; k++) {
				int Cur = Sum[i][k] - Sum[i][j - 1];
				if (Big < Cur) {
					Big = Cur;
					AnswerTwin[i] = make_pair(j, k);
				}
				else if (Big == Cur) {
					if ((AnswerTwin[i].second - AnswerTwin[i].first) > (k - j)) {
						AnswerTwin[i] = make_pair(j, k);
					}
				}
			}
		}
		Answer += Big;
	}
}

void Find_Answer() {
	cout << Answer << "\n";
	for (int i = 1; i <= N; i++) {
		cout << AnswerTwin[i].first << " " << AnswerTwin[i].second << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}