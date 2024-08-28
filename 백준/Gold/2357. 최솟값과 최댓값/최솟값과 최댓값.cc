#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
long long arr[100001];
pair<long long, long long> tree[400004];

pair<long long, long long> dfs(int S, int E, int node) {
	if (S == E) {
		tree[node].first = tree[node].second = arr[S];
		return tree[node];
	}
	int mid = (S + E) >> 1;
	pair<long long, long long> l = dfs(S, mid, node * 2);
	pair<long long, long long> r = dfs(mid + 1, E, node * 2 + 1);
	tree[node].first = min(l.first, r.first);
	tree[node].second = max(l.second, r.second);
	return tree[node];
}

pair<long long, long long> find_val(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return make_pair(INT_MAX, 0);
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) >> 1;
	pair<long long, long long> l = find_val(S, mid, node * 2, left, right);
	pair<long long, long long> r = find_val(mid + 1, E, node * 2 + 1, left, right);
	pair<long long, long long> res;
	res.first = min(l.first, r.first);
	res.second = max(l.second, r.second);
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, N - 1, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		pair<long long, long long> answer = find_val(0, N - 1, 1, a - 1, b - 1);
		cout << answer.first << " " << answer.second << "\n";
	}

	return 0;
}