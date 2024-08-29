#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <algorithm>
#define MAX 200001

using namespace std;
int T, F;
int arr[MAX];
int arr_rank[MAX];
unordered_map<string, int> m;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		arr[i] = -1;
		arr_rank[i] = 1;
	}
	m.clear();
}

int find(int x) {
	if (arr[x] < 0) {
		return x;
	}
	int parent = find(arr[x]);
	arr[x] = parent;

	return parent;
}

int union_set(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		arr[x] = y;
		arr_rank[y] += arr_rank[x];
		arr_rank[x] = 1;
	}
	return arr_rank[y];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> F;
		init();
		int idx = 1;
		for (int i = 0; i < F; i++) {
			string x, y;
			cin >> x >> y;
			if (m.find(x) == m.end()) {
				m.insert(make_pair(x, idx));
				idx++;
			}
			if (m.find(y) == m.end()) {
				m.insert(make_pair(y, idx));
				idx++;
			}
			cout << union_set(m[x], m[y]) << "\n";
		}
	};

	return 0;
}