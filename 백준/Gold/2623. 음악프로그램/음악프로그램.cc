#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M;
vector<int> vec[MAX];
int parent_num[MAX];
queue<int> q;
vector<int> answer;

void dfs() {
	while (!q.empty()) {
		int now_idx = q.front();
		answer.push_back(now_idx);
		q.pop();

		for (int i = 0; i < vec[now_idx].size(); i++) {
			int next_idx = vec[now_idx][i];
			parent_num[next_idx]--;
			if (parent_num[next_idx] == 0) {
				q.push(next_idx);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int num;
		cin >> num;
		int now_size = 0;
		int singer;
		int prev_singer = -1;
		for (int j = 0; j < num; j++) {
			if (j > 0) {
				prev_singer = singer;
			}
			cin >> singer;
			now_size++;
			if (prev_singer != -1) {
				vec[prev_singer].push_back(singer);
				parent_num[singer]++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (parent_num[i] == 0) {
			q.push(i);
		}
	}
	dfs();
	if (answer.size() == N) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}