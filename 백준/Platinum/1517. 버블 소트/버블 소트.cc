#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

// Merge Sort를 이용하나 세그먼트 트리를 이용하여 풀 수도 있는데 잘 몰라서 구글링함.
using namespace std;
int N;
vector<pair<int, int> > vec; // 값, 위치로 이루어지는 pair를 벡터에 저장
int tree[2222222];
long long answer = 0;

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

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		vec.push_back(make_pair(a, i));
	}
	sort(vec.begin(), vec.end());
	int base = 1;
	while (base < N) {
		base *= 2;
	};
	for (auto w : vec) {
		int i = w.second;
		answer += find_sum(1, base, 1, i + 1, base);
		for (int j = base - 1 + i; j; j /= 2) {
			tree[j]++;
		}
	}

	cout << answer << "\n";

	return 0;
}