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
#define MAX 2222
#define INF 1e9+7

using namespace std;
struct SHARK {
	int S, V, I;
};

int N;
vector<SHARK> Shark_vec;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

int Shark_Compare(SHARK A, SHARK B) {
	int cnt = 0;
	if (A.S == B.S) {
		cnt++;
	}
	else if (A.S < B.S) {
		return 0;
	}
	if (A.V == B.V) {
		cnt++;
	}
	else if (A.V < B.V) {
		return 0;
	}
	if (A.I == B.I) {
		cnt++;
	}
	else if (A.I < B.I) {
		return 0;
	}
	if (cnt == 3) {
		return 2;
	}
	return 1;
}

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

	cin >> N;
	Shark_vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> Shark_vec[i].S >> Shark_vec[i].V >> Shark_vec[i].I;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int comp = Shark_Compare(Shark_vec[i], Shark_vec[j]);
			if (comp == 0) { // i번째 상어의 크기, 속도, 지능 중 하나라도 j번째 상어보다 작으면 먹을 수 없다.
				continue;
			}
			else if (comp == 1) { // i번째 상어보다 j번째 상어의 정보가 다 작다면 먹을 수 있다.
				Graph[i].push_back(j + 50);
			}
			else if (comp == 2) { // i번째 상어와 j번째 상어의 정보가 다 같다면
				if (i < j) { // 앞선 순서인 상어가 뒤 순서인 상어를 먹는다.
					Graph[i].push_back(j + 50);
				}
			}
		}
	}
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= N; i++) { // 한 상어는 최대 두 마리의 상어를 먹을 수 있으므로 DFS를 두 번 탐색한다.
		memset(visited, false, sizeof visited);
		DFS(i);
		memset(visited, false, sizeof visited);
		DFS(i);
	}
	for (int i = 51; i <= 50 + N; i++) { // WORK[i]==-1, 즉 잡아먹히지 않은(살아남을 수 있는) 상어의 수를 계산한다.
		answer += (WORK[i] == -1);
	}
	cout << answer << "\n";

	return 0;
}