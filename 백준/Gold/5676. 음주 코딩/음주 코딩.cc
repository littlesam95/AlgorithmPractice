#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, K;
signed long long arr[100001];
signed long long tree[400004];
vector<char> answer;

void init() {
	for (int i = 0; i < 100001; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < 400004; i++) {
		tree[i] = 1;
	}
	answer.clear();
}

signed long long change_one(signed long long num) {
	if (num > 0) {
		return 1;
	}
	else if (num < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

signed long long dfs(int S, int E, int node) {
	if (S == E) {
		return tree[node] = arr[S];
	}
	int mid = (S + E) / 2;
	return tree[node] = change_one(dfs(S, mid, node * 2) * dfs(mid + 1, E, node * 2 + 1));
}

signed long long find_mul(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return 1;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return change_one(find_mul(S, mid, node * 2, left, right) * find_mul(mid + 1, E, node * 2 + 1, left, right));
}

signed long long update(int S, int E, int node, int idx, signed long long num) {
	if ((idx < S) || (idx > E)) {
		return tree[node];
	}
	if (S == E) {
		return tree[node] = num;
	}
	int mid = (S + E) / 2;
	return tree[node] = change_one(update(S, mid, node * 2, idx, num) * update(mid + 1, E, node * 2 + 1, idx, num));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N >> K) {
		init();
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		dfs(0, N - 1, 1);
		for (int i = 0; i < K; i++) {
			char cmd;
			cin >> cmd;
			if (cmd == 'C') {
				int a;
				signed long long b;
				cin >> a >> b;
				a--;
				update(0, N - 1, 1, a, b);
			}
			else if (cmd == 'P') {
				int a, b;
				cin >> a >> b;
				a--;
				b--;
				if (find_mul(0, N - 1, 1, a, b) > 0) {
					answer.push_back('+');
				}
				else if (find_mul(0, N - 1, 1, a, b) < 0) {
					answer.push_back('-');
				}
				else {
					answer.push_back('0');
				}
			}
		}
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i];
		}
		cout << "\n";
	};

	return 0;
}