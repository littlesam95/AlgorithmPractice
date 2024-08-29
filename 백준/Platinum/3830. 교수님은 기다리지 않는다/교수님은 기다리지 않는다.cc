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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int Parent[MAX];
int Dist[MAX];

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
		Dist[i] = 0;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	int PA = Find(Parent[X]);
	Dist[X] += Dist[Parent[X]]; // Dist[Node] = (Node부터 Node의 Parent까지의 거리) + (Node의 Parent부터 Root까지의 거리)
	// Dist[Node]를 갱신하려면, Node의 Parent부터 Root까지의 거리를 더해준다.
	return Parent[X] = PA;
}

void Union(int X, int Y, int W) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX != PY) { // Y가 X보다 W만큼 더 무거우므로, Y의 Parent를 X로 기록해둔다.
		Dist[PY] = (-Dist[Y]) + Dist[X] + W; // 그리고 Parent와 Node의 상대적 무게를 기록한다.
		// Y의 무게는 Y의 Parent와 -Dist[Y]만큼의 무게 차이가 난다.
		Parent[PY] = PX;
	}
}

void Query() {
	while (M--) {
		char CMD;
		cin >> CMD;
		if (CMD == '!') {
			int A, B, W;
			cin >> A >> B >> W;
			Union(A, B, W);
		}
		else if (CMD == '?') {
			int A, B;
			cin >> A >> B;
			int PA = Find(A);
			int PB = Find(B);
			if (PA == PB) {
				cout << Dist[B] - Dist[A] << "\n";
			}
			else {
				cout << "UNKNOWN\n";
			}
		}
	};
}

void Input() {
	while (1) {
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		Init();
		Query();
	};
}

int main() {
	FASTIO
	Input();

	return 0;
}