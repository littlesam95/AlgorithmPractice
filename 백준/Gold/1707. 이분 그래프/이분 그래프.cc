#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int K;
int V, E;
int arr[20001];
vector<int> vec[20001];

void init(){
	for (int i = 0; i < 20001; i++) {
		arr[i] = 0;
		vec[i].clear();
	}
}

void bfs(int x) {
	arr[x] = 1;
	queue<int> q;
	q.push(x);

	while (!q.empty()) {
		int now_vertex = q.front();
		q.pop();

		for (int i = 0; i < vec[now_vertex].size(); i++) {
			if (!arr[vec[now_vertex][i]]) {
				if (arr[now_vertex] == 1) {
					arr[vec[now_vertex][i]] = 2;
				}
				else if (arr[now_vertex] == 2)  {
					arr[vec[now_vertex][i]] = 1;
				}
				q.push(vec[now_vertex][i]);
			}
		}
	};
}

bool isBipartiteGraph() {
	bool flag = true;
	for (int i = 1; i <= V; i++) {
		int tmp = arr[i];
		for (int j = 0; j < vec[i].size(); j++) {
			if (tmp == arr[vec[i][j]]) {
				flag = false;
				break;
			}
		}
	}

	return flag;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K;
	while (K--) {
		cin >> V >> E;
		init();
		for (int i = 0; i < E; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			vec[n1].push_back(n2);
			vec[n2].push_back(n1);
		}
		for (int i = 1; i <= V; i++) {
			if (!arr[i]) {
				bfs(i);
			}
		}
		if (isBipartiteGraph()) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	};

	return 0;
}