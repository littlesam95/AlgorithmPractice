#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
int MAP[MAX];
pair<int, int> Range[2];

void init() {
	for (int i = 0; i < 2; i++) {
		Range[i] = make_pair(0, 0);
	}
}

void DFS(int Depth, int FL, int FR, int SL, int SR, int Next[]) {
	if (Depth == 2) {
		bool Flag = true;
		for (int i = 1; i <= N; i++) {
			if (Next[i] != i) {
				Flag = false;
				break;
			}
		}
		if (Flag) {
			Range[0] = make_pair(FL, FR);
			Range[1] = make_pair(SL, SR);
		}
		return;
	}
	// 앞에서 탐색
	int IDX1 = 0;
	int IDX2 = 0;
	for (int i = 1; i <= N; i++) {
		if (Next[i] != i) {
			IDX1 = i;
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (Next[i] == IDX1) {
			IDX2 = i;
			break;
		}
	}
	if (Depth == 0) {
		reverse(Next + IDX1, Next + IDX2 + 1);
		DFS(Depth + 1, IDX1, IDX2, SL, SR, Next);
		reverse(Next + IDX1, Next + IDX2 + 1);
	}
	else if (Depth == 1) {
		reverse(Next + IDX1, Next + IDX2 + 1);
		DFS(Depth + 1, FL, FR, IDX1, IDX2, Next);
		reverse(Next + IDX1, Next + IDX2 + 1);
	}

	// 뒤에서 탐색
	for (int i = N; i >= 1; i--) {
		if (Next[i] != i) {
			IDX1 = i;
			break;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (Next[i] == IDX1) {
			IDX2 = i;
			break;
		}
	}
	if (Depth == 0) {
		reverse(Next + IDX2, Next + IDX1 + 1);
		DFS(Depth + 1, IDX2, IDX1, SL, SR, Next);
		reverse(Next + IDX2, Next + IDX1 + 1);
	}
	else if (Depth == 1) {
		reverse(Next + IDX2, Next + IDX1 + 1);
		DFS(Depth + 1, FL, FR, IDX2, IDX1, Next);
		reverse(Next + IDX2, Next + IDX1 + 1);
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
	}
	init();
	DFS(0, 0, 0, 0, 0, MAP);
	for (int i = 0; i < 2; i++) {
		if ((Range[i].first == 0) && (Range[i].second == 0)) {
			cout << 1 << " " << 1 << "\n";
		}
		else {
			cout << Range[i].first << " " << Range[i].second << "\n";
		}
	}

	return 0;
}