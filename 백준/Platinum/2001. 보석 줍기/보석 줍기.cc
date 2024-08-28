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
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101
#define K_MAX 15
#define LL long long
#define INF 2e9

using namespace std;
int N, M, K;
int Island[MAX];
vector<pair<int, int> > Vec[MAX];
bool visited[MAX][1 << K_MAX];
int answer = -1;

int Bit_Count(int X) {
	if (X == 0) {
		return 0;
	}
	return (X % 2) + Bit_Count(X / 2);
}

void BFS() {
	queue<pair<int, int> > Q;
	visited[1][0] = true;
	Q.push(make_pair(1, 0));
	if (Island[1] != 0) {
		visited[1][(1 << Island[1])] = true;
		Q.push(make_pair(1, (1 << Island[1])));
	}

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurJ = Q.front().second;
		Q.pop();

		int CurCnt = Bit_Count(CurJ);
		if (CurX == 1) {
			answer = max(answer, CurCnt);
		}

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i].first;
			int nextL = Vec[CurX][i].second;
			int nextisJ = Island[Vec[CurX][i].first];
			if (CurCnt > nextL) {
				continue;
			}
			// 보석을 안 줍는다
			if (!visited[nextX][CurJ]) {
				visited[nextX][CurJ] = true;
				Q.push(make_pair(nextX, CurJ));
			}
			// 보석이 있으면 줍는다
			if (nextisJ != 0) {
				bool isPicked = (CurJ & (1 << nextisJ));
				if (!isPicked) {
					int nextJ = CurJ | (1 << nextisJ);
					if (!visited[nextX][nextJ]) {
						visited[nextX][nextJ] = true;
						Q.push(make_pair(nextX, nextJ));
					}
				}
			}
		}
	};
}

int main() {
	FIRST
	cin >> N >> M >> K;
	for (int i = 1; i <= K; i++) {
		int X;
		cin >> X;
		Island[X] = i;
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Vec[A].push_back(make_pair(B, C));
		Vec[B].push_back(make_pair(A, C));
	}
	BFS();
	cout << answer << "\n";

	return 0;
}