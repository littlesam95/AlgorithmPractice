#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 32001

using namespace std;
int N, M;
vector<int> vec[MAX];
int parent_num[MAX];
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> answer;

void dfs() {
	while (!pq.empty()) {
		int now_idx = pq.top();
		answer.push_back(now_idx);
		pq.pop();

		for (int i = 0; i < vec[now_idx].size(); i++) {
			int next_idx = vec[now_idx][i];
			parent_num[next_idx]--;
			if (parent_num[next_idx] == 0) {
				pq.push(next_idx);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		parent_num[y]++;
		vec[x].push_back(y);
	}
	for (int i = 1; i <= N; i++) {
		if (parent_num[i] == 0) {
			pq.push(i);
		}
	}
	dfs();
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
    
	return 0;
}