#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 40001

// 최소 공통 조상(LCA) 알고리즘
using namespace std;
int N, M;
int a, b, c;
int depth[MAX_NODE]; // node의 깊이(레벨)
int ac[MAX_NODE][20]; // ac[x][y] : x의 2^y번째 조상
int parent[MAX_NODE];
bool visited[MAX_NODE];
vector<pair<int, int> > vec[MAX_NODE];
int max_level;

void init() {
	N = 0;
	a = 0;
	b = 0;
	for (int i = 0; i < MAX_NODE; i++) {
		depth[i] = 0;
		parent[i] = 0;
		vec[i].clear();
		for (int j = 0; j < 20; j++) {
			ac[i][j] = 0;
		}
	}
}

void init2() {
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
	}
}

void find_parent(int S) {
	visited[S] = true;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[vec[S][i].first]) {
			parent[vec[S][i].first] = S;
			find_parent(vec[S][i].first);
		}
	}
}

void make_tree(int S, int parent) {
	depth[S] = depth[parent] + 1;
	ac[S][0] = parent;
	max_level = (int)floor(log2(MAX_NODE));
	for (int i = 1; i <= max_level; i++) {
		int tmp = ac[S][i - 1];
		ac[S][i] = ac[tmp][i - 1];
	}
	int len = vec[S].size();
	for (int i = 0; i < len; i++) {
		int there = vec[S][i].first;
		if (there != parent) {
			make_tree(there, S);
		}
	}
}

int find_len(int S, int E) {
	if (S == E) {
		return 0;
	}
	int now_len = 0;
	int parent_node = parent[S];
	for (int i = 0; i < vec[S].size(); i++) {
		if (parent_node == vec[S][i].first) {
			now_len = vec[S][i].second;
		}
	}
	now_len += find_len(parent_node, E);
	return now_len;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	init2();
	find_parent(1);
	int root;
	for (int i = 1; i <= N; i++) {
		if (!parent[i]) {
			root = i;
			break;
		}
	}
	depth[0] = -1;
	make_tree(root, 0);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> a >> b;
		A = a;
		B = b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) {
				int tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]]) {
					b = ac[b][i];
				}
			}
		}

		int answer = a;
		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				answer = ac[a][i];
			}
		}
		cout << find_len(A, answer) + find_len(B, answer) << "\n";
	}

	return 0;
}