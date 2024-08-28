#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<vector<int> > vec;
bool visit[101] = { false, };
int computer = 0;
int res = 0;

void dfs(int x) {
	res++;
	visit[x] = true;

	int size = vec[x].size();
	for (int i = 0; i < size; i++) {
		if (!visit[vec[x][i]]) { // node로 연결된 edge 중 탐색하지 않은 edge 탐색
			dfs(vec[x][i]);
		}
	}
	return;
}

int main() {
	int N, start, end;
	cin >> computer >> N; // 컴퓨터의 수, 연결된 컴퓨터 쌍 입력
	vec.resize(computer + 1);
	for (int i = 0; i < N; i++) {
		cin >> start >> end; // 연결된 컴퓨터의 번호 쌍 입력
		vec[start].push_back(end); // i번째 벡터에 j push
		vec[end].push_back(start); // j번째 벡터에 i push
	}

	dfs(1);

	cout << res - 1;

	return 0;
}