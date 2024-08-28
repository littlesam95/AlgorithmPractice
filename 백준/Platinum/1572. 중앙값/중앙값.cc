#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1000001
#define LL long long
#define ULL unsigned long long
#define MAXV 65535
#define INF 1e9

using namespace std;
ULL N, K;
ULL Tree_Height, Tree_Size;
ULL SegTree[MAX];
ULL MAP[MAX];
ULL answer = 0;

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
}

void Make_SegTree(ULL Node, ULL S, ULL E, ULL VAL, ULL DIFF) {
	// 세그먼트 트리에서의 Index는 온도를 의미한다. 이분 탐색을 통하여 온도의 개수를 누적시킨다.
	if (S == E) {
		SegTree[Node] += DIFF;
		return;
	}
	ULL MID = (S + E) / 2;
	if (VAL <= MID) {
		Make_SegTree(Node * 2, S, MID, VAL, DIFF);
	}
	else {
		Make_SegTree(Node * 2 + 1, MID + 1, E, VAL, DIFF);
	}
	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
}

ULL Find_Value(ULL Node, ULL S, ULL E, ULL VAL) {
	if (S == E) {
		return S;
	}
	ULL MID = (S + E) / 2;
	if (VAL <= SegTree[Node * 2]) {
		return Find_Value(Node * 2, S, MID, VAL);
	}
	else {
		return Find_Value(Node * 2 + 1, MID + 1, E, VAL - SegTree[Node * 2]);
	}
}

void Settings() {
	for (int i = 0; i < (K - 1); i++) { // 0번째 수부터 K-1개의 수를 세그먼트 트리에 업데이트시킨다.
		Make_SegTree(1, 0, MAXV, MAP[i], 1);
	}
}

void Find_Answer() {
	int IDX = 0;
	for (int i = (K - 1); i < N; i++) {
		Make_SegTree(1, 0, MAXV, MAP[i], 1);
		answer += Find_Value(1, 0, MAXV, (K + 1) / 2);
		Make_SegTree(1, 0, MAXV, MAP[IDX++], -1);
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}