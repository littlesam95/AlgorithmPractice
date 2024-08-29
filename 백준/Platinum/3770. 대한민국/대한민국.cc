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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M, K;
vector<int> Vec[MAX];
vector<int> SegTree;
LL answer;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Vec[i].clear();
	}
	SegTree.clear();
	answer = 0;
	int Height = (int)ceil(log2(N));
	int Size = (1 << (Height + 1));
	SegTree.resize(Size);
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

void Find_Answer(int Testcase) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Vec[i].size(); j++) {
			int X = Vec[i][j];
			answer += Query(1, 1, M, X + 1, M);
		}
		for (int j = 0; j < Vec[i].size(); j++) {
			int X = Vec[i][j];
			Update_Tree(1, 1, M, X);
		}
	}
	cout << "Test case " << Testcase << ": " << answer << "\n";
}

void Input() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K;
		Init();
		for (int i = 0; i < K; i++) {
			int I, J;
			cin >> I >> J;
			Vec[I].push_back(J);
		}
		Find_Answer(i);
	};
}

int main() {
	FASTIO
	Input();

	return 0;
}