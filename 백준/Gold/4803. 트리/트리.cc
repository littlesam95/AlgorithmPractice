#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;
int N, M;
bool visited[510];
bool passed[510];
vector<int> vec[510];
bool isTree;
int answer = 0;
int idx = 1;

void init() {
	for (int i = 0; i < 510; i++) {
		vec[i].clear();
		visited[i] = false;
		passed[i] = false;
	}
	answer = 0;
}

int vertex_num(int S) {
	int cnt = 1;
	visited[S] = true;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[vec[S][i]]) {
			cnt += vertex_num(vec[S][i]);
		}
	}

	return cnt;
}

int edge_num(int S) {
	int cnt = vec[S].size();
	passed[S] = 1;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!passed[vec[S][i]]) {
			cnt += edge_num(vec[S][i]);
		}
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N >> M;
		if ((N == 0) && (M == 0)) {
			break;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				int V = vertex_num(i);
				int E = edge_num(i);
				if ((V - 1) == (E / 2)) {
					answer++;
				}
			}
		}

		cout << "Case " << idx++ << ": ";
		if (answer > 1) {
			cout << "A forest of " << answer << " trees." << "\n";
		}
		else if (answer == 1) {
			cout << "There is one tree." << "\n";
		}
		else {
			cout << "No trees." << "\n";
		}
	};

	return 0;
}