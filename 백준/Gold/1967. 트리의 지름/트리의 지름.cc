#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int a, b, c;
vector<pair<int, int> > vec[10010];
bool visited[10010];
int answer = 0;
int end_point = 0;

void init() {
	for (int i = 0; i < 10010; i++) {
		visited[i] = false;
	}
}

void dfs(int S, int len) {
	if (visited[S]) {
		return;
	}
	visited[S] = true;
	if (answer < len) {
		answer = len;
		end_point = S;
	}

	for (int i = 0; i < vec[S].size(); i++) {
		dfs(vec[S][i].first, vec[S][i].second + len);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c)); // 부모 자식 노드간의 정보와 가중치를 pair로 저장한다.
	}
	dfs(1, 0); // root 노드부터 탐색해서 가장 긴 길이를 가진 노드를 끝점으로 한다.
	answer = 0;
	init(); // 길이를 저장한 answer 변수와 방문했음을 표시하는 배열 visited를 0으로 초기화
	dfs(end_point, 0); // 지정했었던 끝점부터 다시 탐색해서 트리의 지름을 찾는다.
	cout << answer << "\n";

	return 0;
}