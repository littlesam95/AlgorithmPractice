#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 1000001

using namespace std;
int N;
vector<int> vec[10010];
int parent[10010];
int level[10010];
bool visited[10010];
vector<int> vec2;
int max_level = 1;

struct Node {
	int data;
	Node* left;
	Node* right;
};

void init() {
	for (int i = 0; i < 10010; i++) {
		parent[i] = 0;
	}
}

void dfs(int S, int depth) {
	visited[S] = true;
	level[S] = depth;
	if (max_level < depth) {
		max_level = depth;
	}
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[vec[S][i]]) {
			dfs(vec[S][i], depth + 1);
		}
	}
}

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}

	return node;
}


Node* make_tree(Node* node, int S) {
	node = insert(node, S);
	if (vec[S][0] != -1) {
		node->left = make_tree(node->left, vec[S][0]);
	}
	if (vec[S][1] != -1) {
		node->right = make_tree(node->right, vec[S][1]);
	}

	return node;
}

void inOrder(Node* node) {
	if (node->left != NULL) {
		inOrder(node->left);
	}
	vec2.push_back(node->data);
	if (node->right != NULL) {
		inOrder(node->right);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n, l, r;
		cin >> n >> l >> r;
		vec[n].push_back(l);
		vec[n].push_back(r);
		if (l != -1) {
			parent[l] = n;
		}
		if (r != -1) {
			parent[r] = n;
		}
	}
	int root;
	for (int i = 1; i <= N; i++) {
		if (!parent[i]) {
			root = i;
			break;
		}
	}
	dfs(root, 1);
	Node* root_node = NULL;
	root_node = make_tree(root_node, root);
	inOrder(root_node);

	int answer_width = 0;
	int answer_level;
	for (int i = 1; i <= max_level; i++) {
		int start_idx, end_idx;
		for (int j = 0; j < vec2.size(); j++) {
			if (level[vec2[j]] == i) {
				start_idx = j;
				break;
			}
		}
		for (int j = (vec2.size() - 1); j >= 0; j--) {
			if (level[vec2[j]] == i) {
				end_idx = j;
				break;
			}
		}
		int width = (end_idx - start_idx) + 1;
		if (answer_width < width) {
			answer_width = width;
			answer_level = i;
		}
	}

	cout << answer_level << " " << answer_width << "\n";

	return 0;
}