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
int N, M;
int WANT[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

// 이분 매칭(Bipartite Matching)
bool DFS(int X) {
	for (int i = 0; i < Graph[X].size(); i++) {
		int Next = Graph[X][i];
		if (visited[Next]) {
			continue;
		}
		visited[Next] = true;
		if ((WANT[Next] == 0) || DFS(WANT[Next])) { // 지금 노트북(Next)과 매칭된 주인이 없다면 노트북과 현재 사람(X)을 매칭시키고 true를 return한다.
			// 또는 지금 노트북과 매칭된 주인이 있다면, 그 주인이 원하는 노트북을 탐색(DFS 재귀)
			WANT[Next] = X;
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) { // A번 사람은 B번째 노트북을 자신의 노트북이라고 생각한다.
		int A, B;
		cin >> A >> B;
		Graph[A].push_back(B);
	}
	memset(WANT, 0, sizeof WANT);
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) { // 1번째 사람부터 N번째 사람까지, 원하는 노트북을 탐색한다. 만약 노트북과 매칭에 성공한 사람이라면 answer가 증가한다.
			// DFS로 문제를 해결하기 때문에, 최악의 경우 시간 복잡도는 O(N * M)이 된다.
			answer++;
		}
	}
	cout << answer << "\n";

	return 0;
}