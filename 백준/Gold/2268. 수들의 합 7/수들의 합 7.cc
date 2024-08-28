#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M;
long long arr[1000001];
long long tree[4000004];

long long dfs(int S, int E, int node) {
	if (S == E) {
		return tree[node] = arr[S];
	}
	int mid = (S + E) / 2;
	return tree[node] = dfs(S, mid, node * 2) + dfs(mid + 1, E, node * 2 + 1);
}

long long find_sum(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return 0;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return find_sum(S, mid, node * 2, left, right) + find_sum(mid + 1, E, node * 2 + 1, left, right);
}

void update(int S, int E, int node, int idx, long long diff) {
	if ((idx < S) || (idx > E)) {
		return;
	}
	tree[node] += diff;
	if (S == E) {
		return;
	}
	int mid = (S + E) / 2;
	update(S, mid, node * 2, idx, diff);
	update(mid + 1, E, node * 2 + 1, idx, diff);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
	dfs(0, N - 1, 1);
	for (int i = 0; i < M; i++) {
		int calc;
		cin >> calc;
		if (calc) {
			int a;
			long long b;
			cin >> a >> b;
			a--;
			long long diff = b - arr[a];
			arr[a] = b;
			update(0, N - 1, 1, a, diff);
		}
		else if (!calc) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			if (a > b) {
				cout << find_sum(0, N - 1, 1, b, a) << "\n";
			}
			else {
				cout << find_sum(0, N - 1, 1, a, b) << "\n";
			}
		}
	}

	return 0;
}