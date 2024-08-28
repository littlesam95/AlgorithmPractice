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
#define MAX 500001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int MAP[MAX];
vector<int> SegTree;

void Update_SegTree(int Node, int S, int E, int Val, int Diff) {
	if (S == E) {
		SegTree[Node] += Diff;
		return;
	}
	int M = (S + E) / 2;
	if (Val <= M) {
		Update_SegTree(Node * 2, S, M, Val, Diff);
	}
	else {
		Update_SegTree(Node * 2 + 1, M + 1, E, Val, Diff);
	}
	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
}

int Find_Value(int Node, int S, int E, int Val) {
	if (S == E) {
		return S;
	}
	int M = (S + E) / 2;
	if (Val <= SegTree[Node * 2]) {
		return Find_Value(Node * 2, S, M, Val);
	}
	else {
		return Find_Value(Node * 2 + 1, M + 1, E, Val - SegTree[Node * 2]);
	}
}

void Settings() {
	int Tree_Height = (int)ceil(log2(500000));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegTree.resize(Tree_Size);
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
		Update_SegTree(1, 1, 500000, i, MAP[i]);
	}
}

void Find_Answer() {
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (A == 1) {
			int C;
			cin >> C;
			MAP[B] += C;
			Update_SegTree(1, 1, 500000, B, C);
		}
		else if (A == 2) {
			cout << Find_Value(1, 1, 500000, B) << "\n";
		}
	}
}

int main() {
	FASTIO
	Settings();
	Input();
	Find_Answer();

	return 0;
}