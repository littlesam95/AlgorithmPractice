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
#define MAX 3
#define LL long long
#define INF 1e9

using namespace std;
pair<int, int> Time[MAX];
int H, M, S;
int Answer[MAX][MAX];


void Input() {
	for (int i = 0; i < MAX; i++) {
		cin >> H >> M >> S;
		Time[i].first = H * 3600 + M * 60 + S;
		cin >> H >> M >> S;
		Time[i].second = H * 3600 + M * 60 + S;
	}
}

void Settings() {
	for (int i = 0; i < MAX; i++) {
		int All = Time[i].second - Time[i].first;
		Answer[i][0] = All / 3600;
		All %= 3600;
		Answer[i][1] = All / 60;
		All %= 60;
		Answer[i][2] = All;
	}
}

void Find_Answer() {
	for (int i = 0; i < MAX; i++) {
		cout << Answer[i][0] << " " << Answer[i][1] << " " << Answer[i][2] << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}