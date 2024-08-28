#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;
string N;
int K, len;

int Invert(string S) {
	int res = 0;
	for (int i = 0; i < S.size(); i++) {
		res += (S[i] - '0');
		if (i != S.size() - 1) {
			res *= 10;
		}
	}
	return res;
}

void BFS(string S) {
	queue<string> q;
	q.push(S);
	int nowK = 0;
	int Max = 0;

	while (!q.empty() && (nowK < K)) {
		int qsize = q.size();
		set<string> visited;

		for (int i = 0; i < qsize; i++) {
			string nowS = q.front();
			q.pop();
			for (int j = 0; j < len - 1; j++) {
				for (int k = j + 1; k < len; k++) {
					if ((j == 0) && (nowS[k] == '0')) {
						continue;
					}
					swap(nowS[j], nowS[k]);
					if (visited.find(nowS) == visited.end()) {
						if ((nowK == K - 1) && (Max < Invert(nowS))) {
							Max = Invert(nowS);
						}
						q.push(nowS);
						visited.insert(nowS);
					}
					swap(nowS[j], nowS[k]);
				}
			}
		}
		nowK++;
	};
	if (nowK != K) {
		cout << -1 << "\n";
	}
	else {
		cout << Max << "\n";
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	len = N.length();
	if ((len == 1) || ((len == 2) && (Invert(N) % 10 == 0))) {
		cout << -1 << "\n";
		exit(0);
	}
	BFS(N);

	return 0;
}