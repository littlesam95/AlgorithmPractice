#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 21
#define INF 2e9

using namespace std;
int N;
string W;
int len;

void DFS(int idx, string res) {
	if (idx == len - 1) {
		cout << res << "\n";
		return;
	}
	for (int i = idx; i < len; i++) {
		if ((i != idx) && (res[i] == res[idx])){
			continue;
		}
		if (res[i] != res[idx]) {
			char C = res[i];
			res[i] = res[idx];
			res[idx] = C;
		}
		DFS(idx + 1, res);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) {
		cin >> W;
		len = W.size();
		sort(W.begin(), W.end());
		DFS(0, W);
	};

	return 0;
}