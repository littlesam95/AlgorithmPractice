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
#define MAX 1005
#define INF 1e9+7

using namespace std;
int N, K;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

// 쾨니그의 정리(Kőnig's Theorem)
bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WORK[Next] == -1) || DFS(WORK[Next])) {
			WORK[Next] = E;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= K; i++) { // 행을 담당하는 정점과 열을 담당하는 정점을 각각 만들어주면, 이분 그래프가 만들어진다. 이 이분 그래프를 이용하여 이분 매칭을 진행한다.
		int Y, X;
		cin >> Y >> X;
		Graph[Y].push_back(X + 500);
	}
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= 500; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}