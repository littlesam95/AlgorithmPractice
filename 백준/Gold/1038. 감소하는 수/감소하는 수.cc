#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
vector<long long> vec;

void dfs(int X, long long sum) {
	vec.push_back(sum);
	for (long long i = X - 1; i >= 0; i--) {
		dfs(i, sum * 10 + i);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i <= 9; i++) {
		dfs(i, i);
	}
	sort(vec.begin(), vec.end());
	if (vec.size() > N) {
		cout << vec[N] << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}