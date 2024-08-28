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
#define MAX_N 50001
#define MAX_Y 1000001
#define LL long long
#define INF 1e11

using namespace std;
struct INFO {
	double Cost;
	int X, Y, I;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Cost > B.Cost);
	}
};

int N, F;
vector<pair<int, int> > Pos;
vector<pair<int, int> > Edge[MAX_Y];
bool visited[MAX_N];
double answer = INF;

void Input() {
	cin >> N >> F;
	for (int i = 1; i <= N; i++) {
		int X, Y;
		cin >> X >> Y;
		Edge[Y].push_back(make_pair(X, i));
	}
	for (int i = 0; i < MAX_Y; i++) {
		sort(Edge[i].begin(), Edge[i].end());
	}
}

void Dijkstra() {
	priority_queue<INFO, vector<INFO>, COMP> PQ;
	PQ.push({ 0,0,0,0 });

	while (!PQ.empty()) {
		INFO CurInfo = PQ.top();
		PQ.pop();
		double CurCost = CurInfo.Cost;
		int CurX = CurInfo.X;
		int CurY = CurInfo.Y;
		int CurI = CurInfo.I;

		if (CurY >= F) {
			answer = CurCost;
			return;
		}
		if (visited[CurI]) {
			continue;
		}
		visited[CurI] = true;

		for (int i = -2; i <= 2; i++) {
			int nextY = CurY + i;
			if ((nextY >= 0) && (nextY < MAX_Y)) {
				int A = lower_bound(Edge[nextY].begin(), Edge[nextY].end(), make_pair(CurX - 2, 0)) - Edge[nextY].begin();
				int B = upper_bound(Edge[nextY].begin(), Edge[nextY].end(), make_pair(CurX + 2, 0)) - Edge[nextY].begin();
				for (A = 0; A < Edge[nextY].size(); A++) {
					if (abs(CurX - Edge[nextY][A].first) <= 2 && !visited[Edge[nextY][A].second]) {
						double nextCost = CurCost + sqrt(pow(CurX - Edge[nextY][A].first, 2) + pow(CurY - nextY, 2));
						PQ.push({ nextCost,Edge[nextY][A].first,nextY,Edge[nextY][A].second });
					}
				}
			}
		}
	};
}

void Find_Answer() {
	if (answer == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << fixed;
		cout.precision(0);
		cout << round(answer) << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Dijkstra();
	Find_Answer();

	return 0;
}