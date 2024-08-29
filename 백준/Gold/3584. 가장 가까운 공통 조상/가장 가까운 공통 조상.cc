#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 100001

// 최소 공통 조상(LCA) 알고리즘
using namespace std;
int T;
int N;
int a, b;
int depth[MAX_NODE]; // node의 깊이(레벨)
int ac[MAX_NODE][20]; // ac[x][y] : x의 2^y번째 조상
int parent[MAX_NODE];
vector<int> vec[MAX_NODE];
int max_level;

void init() {
	N = 0;
	a = 0;
	b = 0;
	for (int i = 0; i < 10010; i++) {
		depth[i] = 0;
		parent[i] = 0;
		vec[i].clear();
		for (int j = 0; j < 20; j++) {
			ac[i][j] = 0;
		}
	}
}

void make_tree(int S, int parent) {
	depth[S] = depth[parent] + 1; // 노드 S의 깊이는 부모 노드의 깊이 + 1
	ac[S][0] = parent; // S의 1번째 조상은 부모 노드
	max_level = (int)floor(log2(MAX_NODE)); // MAX_NODE에 log2를 씌워 내림해준다.
	for (int i = 1; i <= max_level; i++) {
		int tmp = ac[S][i - 1]; // 노드 S의 2^(i-1)번째 조상
		/*
			즉 ac[S][i] = ac[tmp][i - 1]은
			S의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
			i = 3일 때 S의 8번째 조상은 tmp의 4번째 조상과 같다.
		*/
		ac[S][i] = ac[tmp][i - 1];
	}
	int len = vec[S].size(); // S와 연결되어 있는 노드의 개수
	for (int i = 0; i < len; i++) {
		int there = vec[S][i];
		if (there != parent) { // there 노드가 S의 부모 노드가 아니라면 there 노드는 S의 자식 노드이므로 dfs 시작
			make_tree(there, S);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init(); // depth, parent, ac 배열 및 vec 벡터 초기화
		cin >> N;
		for (int i = 1; i < N; i++) { // N-1개의 트리를 구성하는 간선 정보 입력
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
			parent[b] = a; // b의 부모는 a
		}

		int root;
		for (int i = 1; i <= N; i++) {
			if (!parent[i]) { // 부모가 없다면(0) 그 노드가 루트 노드라는 뜻이다.
				root = i;
				break;
			}
		}
		depth[0] = -1;
		make_tree(root, 0); // 루트 노드부터 탐색 진행, 루트 노드의 depth는 0

		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) { // depth[b] >= depth[a]가 되도록 swap
				int tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			// b를 올려서 depth를 맞춰준다.
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]]) { // b의 2^i번째 조상이 a의 depth보다 크거나 같으면 계속 조상을 타고 간다.
					b = ac[b][i];
				}
			}
		}

		int answer = a;
		if (a != b) { // a와 b가 다르다면 현재 depth가 같으니, depth를 계속 올려 조상이 같아질 때까지 반복
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				answer = ac[a][i];
			}
		}

		cout << answer << "\n";
	};

	return 0;
}