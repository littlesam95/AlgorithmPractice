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
#define MAX 101001
#define LL long long
#define INF 2e9

using namespace std;
int N, K, M;
vector<int> Platform[MAX];
bool visited[MAX];

int BFS() {
	queue<pair<int, int> > Q;
	visited[1] = true;
	Q.push(make_pair(1, 1));

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurCnt = Q.front().second;
		Q.pop();

		if (CurX == N) {
			return CurCnt;
		}

		for (int i = 0; i < Platform[CurX].size(); i++) {
			int nextX = Platform[CurX][i];
			if (!visited[nextX]) {
				visited[nextX] = true;
				if (nextX > N) {
					Q.push(make_pair(nextX, CurCnt));
				}
				else {
					Q.push(make_pair(nextX, CurCnt + 1));
				}
			}
		}
	};

	return -1;
}

int main() {
	FIRST
	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < K; j++) {
			int X;
			cin >> X;
			Platform[X].push_back(i + N);
			Platform[i + N].push_back(X);
		}
	}
	cout << BFS() << "\n";

	return 0;
}