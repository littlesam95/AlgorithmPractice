#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
vector<pair<int, bool> > vec[30];

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
	else if (data <= node->data) {
		node->left = insert(node->left, data);
	}
	else {
		node->right = insert(node->right, data);
	}
	return node;
}

void postOrder(Node* node) {
	if (node->left != NULL) {
		postOrder(node->left);
	}
	if (node->right != NULL) {
		postOrder(node->right);
	}

	cout << node->data << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	Node* root = NULL;
	while (cin >> N) {
		if (N == EOF) {
			break;
		}
		root = insert(root, N);
	};
	postOrder(root);

	return 0;
}