#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;
int T;
int N;
int preorder_arr[1010];
int inorder_arr[1010];

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = node->right = NULL;
	}

	return node;
}

Node* dfs(int S, int left, int right, Node* node) {
	if (left > right) {
		return NULL;
	}
	node = insert(node, preorder_arr[S]);
	int mid;
	for (int i = 0; i < N; i++) {
		if (inorder_arr[i] == preorder_arr[S]) {
			mid = i;
			break;
		}
	}
	int left_left = left;
	int left_right = mid - 1;
	int left_size = left_right - left_left + 1;
	int right_left = mid + 1;
	int right_right = right;
	int right_size = right_right - right_left + 1;
	int left_root_idx = S + 1;
	int right_root_idx = left_root_idx + left_size;
	node->left = dfs(left_root_idx, left_left, left_right, node->left);
	node->right = dfs(right_root_idx, right_left, right_right, node->right);

	return node;
}

void postOrder(Node* node) {
	if (node->left != NULL) {
		postOrder(node->left);
	}
	if (node->right != NULL) {
		postOrder(node->right);
	}
	cout << node->data << " ";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> preorder_arr[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> inorder_arr[i];
		}

		Node* root = NULL;
		root = dfs(0, 0, N - 1, root);
		postOrder(root);
		cout << "\n";
	};

	return 0;
}