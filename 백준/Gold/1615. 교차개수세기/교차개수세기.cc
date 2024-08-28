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
#define MAX 2001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
vector<int> Vec[MAX];
vector<int> SegTree;
LL answer = 0;

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int I, J;
		cin >> I >> J;
		Vec[I].push_back(J);
	}
}

void Update_Tree(int Node, int Start, int End, int Val) {
	if (Start == End) {
		SegTree[Node] += 1;
		return;
	}
	int Mid = (Start + End) / 2;
	if (Val <= Mid) {
		Update_Tree(Node * 2, Start, Mid, Val);
	}
	else {
		Update_Tree(Node * 2 + 1, Mid + 1, End, Val);
	}
	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
}

LL Query(int Node, int Start, int End, int Left, int Right) {
	if ((End < Left) || (Right < Start)) {
		return 0;
	}
	if ((Left <= Start) && (End <= Right)) {
		return SegTree[Node];
	}
	int Mid = (Start + End) / 2;
	return Query(Node * 2, Start, Mid, Left, Right) + Query(Node * 2 + 1, Mid + 1, End, Left, Right);
}

void Settings() {
	int Height = (int)ceil(log2(N));
	int Size = (1 << (Height + 1));
	SegTree.resize(Size);
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Vec[i].size(); j++) {
			int X = Vec[i][j];
			answer += Query(1, 1, N, X + 1, N);
		}
		for (int j = 0; j < Vec[i].size(); j++) {
			int X = Vec[i][j];
			Update_Tree(1, 1, N, X);
		}
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