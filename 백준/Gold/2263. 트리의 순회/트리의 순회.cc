#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int inorder_arr[100010];
int postorder_arr[100010];

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
	node = insert(node, postorder_arr[S]);
	int mid;
	for (int i = 0; i < n; i++) {
		if (inorder_arr[i] == postorder_arr[S]) {
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
	int right_root_idx = S - 1;
	int left_root_idx = right_root_idx - right_size;
	node->left = dfs(left_root_idx, left_left, left_right, node->left);
	node->right = dfs(right_root_idx, right_left, right_right, node->right);

	return node;
}

void preOrder(Node* node) {
	cout << node->data << " ";
	if (node->left != NULL) {
		preOrder(node->left);
	}
	if (node->right != NULL) {
		preOrder(node->right);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inorder_arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder_arr[i];
	}
	Node* root = NULL;
	root = dfs(n - 1, 0, n - 1, root);
	preOrder(root);

	return 0;
}