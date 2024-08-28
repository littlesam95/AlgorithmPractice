#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 101

using namespace std;
int N, M;
int parent_num[MAX];
int parts[MAX];
vector<pair<int, int> > vec[MAX];
queue<int> q;
vector<int> answer;

void bfs(int x) {
	q.push(x);
	parts[x] = 1;

	while (!q.empty()) {
		int now_idx = q.front();
		q.pop();

		if (vec[now_idx].empty()) {
			answer.push_back(now_idx);
		}
		for (int i = 0; i < vec[now_idx].size(); i++) {
			int parts_x = vec[now_idx][i].first;
			parts[parts_x] += (parts[now_idx] * vec[now_idx][i].second);
			parent_num[parts_x]--;
			if (parent_num[parts_x] == 0) {
				q.push(parts_x);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int X, Y, K;
		cin >> X >> Y >> K;
		vec[X].push_back(make_pair(Y, K));
		parent_num[Y]++;
	}
	bfs(N);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " " << parts[answer[i]] << "\n";
	}

	return 0;
}