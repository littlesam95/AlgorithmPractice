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
#define MAX 301
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End, Cost;
};

int N;
int Parent[MAX];
vector<INFO> Edge;
LL answer = 0;

void Init() {
	for (int i = 0; i <= N; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) {
		Parent[PY] = PX;
	}
	else {
		Parent[PX] = PY;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
}

void Input() {
	cin >> N;
	Init();
	for (int i = 1; i <= N; i++) {
		int W;
		cin >> W;
		Edge.push_back({ 0,i,W });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int P;
			cin >> P;
			if (i < j) {
				Edge.push_back({ i,j,P });
			}
		}
	}
}

void Settings() {
	sort(Edge.begin(), Edge.end(), Comp);
	for (int i = 0; i < Edge.size(); i++) {
		int S = Edge[i].Start;
		int E = Edge[i].End;
		int C = Edge[i].Cost;
		if (Find(S) != Find(E)) {
			Union(S, E);
			answer += C;
		}
	}
}

void Find_Answer() {
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}