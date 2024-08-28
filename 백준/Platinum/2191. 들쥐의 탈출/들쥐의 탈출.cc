#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define INF 1e9+7

using namespace std;
int N, M, S, V;
pair<double, double> MOUSE[MAX];
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer;

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (!visited[Next]) {
			visited[Next] = true;
			if ((WORK[Next] == 0) || DFS(WORK[Next])) {
				WORK[Next] = E;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S >> V;
	answer = N;
	for (int i = 1; i <= N; i++) {
		double X, Y;
		cin >> X >> Y;
		MOUSE[i] = make_pair(X, Y);
	}
	for (int j = 1; j <= M; j++) {
		double X, Y;
		cin >> X >> Y;
		for (int i = 1; i <= N; i++) {
			double NewX = (MOUSE[i].first - X) * (MOUSE[i].first - X);
			double NewY = (MOUSE[i].second - Y) * (MOUSE[i].second - Y);
			double Dist = sqrt(NewX + NewY);
			double Escape_Time = Dist / (double)V;
			if (Escape_Time <= S) {
				Graph[i].push_back(j);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer--;
		}
	}
	cout << answer << "\n";

	return 0;
}