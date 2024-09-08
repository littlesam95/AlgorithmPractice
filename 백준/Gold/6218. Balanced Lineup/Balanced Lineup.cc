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
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
int Tree_Height, Tree_Size;
vector<int> MinTree;
vector<int> MaxTree;
int MAP[MAX];

void Input() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
}

int Make_Min_SegTree(int Node, int S, int E) {
	if (S == E) {
		return MinTree[Node] = MAP[S];
	}

	int MID = (S + E) / 2;
	int L = Make_Min_SegTree(Node * 2, S, MID);
	int R = Make_Min_SegTree(Node * 2 + 1, MID + 1, E);
	MinTree[Node] = min(L, R);
	return MinTree[Node];
}

int Make_Max_SegTree(int Node, int S, int E) {
	if (S == E) {
		return MaxTree[Node] = MAP[S];
	}

	int MID = (S + E) / 2;
	int L = Make_Max_SegTree(Node * 2, S, MID);
	int R = Make_Max_SegTree(Node * 2 + 1, MID + 1, E);
	MaxTree[Node] = max(L, R);
	return MaxTree[Node];
}

int Find_Min_Value(int Node, int S, int E, int L, int R) {
	if ((E < L) || (R < S)) {
		return INF;
	}

	if ((L <= S) && (E <= R)) {
		return MinTree[Node];
	}
	int MID = (S + E) / 2;
	int LV = Find_Min_Value(Node * 2, S, MID, L, R);
	int RV = Find_Min_Value(Node * 2 + 1, MID + 1, E, L, R);
	return min(LV, RV);
}

int Find_Max_Value(int Node, int S, int E, int L, int R) {
	if ((E < L) || (R < S)) {
		return -1;
	}

	if ((L <= S) && (E <= R)) {
		return MaxTree[Node];
	}
	int MID = (S + E) / 2;
	int LV = Find_Max_Value(Node * 2, S, MID, L, R);
	int RV = Find_Max_Value(Node * 2 + 1, MID + 1, E, L, R);
	return max(LV, RV);
}

void Settings() {
	Tree_Height = (int)ceil(log2(N));
	Tree_Size = (1 << (Tree_Height + 1));
	MinTree.resize(Tree_Size);
	MaxTree.resize(Tree_Size);
	Make_Min_SegTree(1, 0, N - 1);
	Make_Max_SegTree(1, 0, N - 1);
}

void Find_Answer() {
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		A--;
		B--;
		cout << Find_Max_Value(1, 0, N - 1, A, B) - Find_Min_Value(1, 0, N - 1, A, B) << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}