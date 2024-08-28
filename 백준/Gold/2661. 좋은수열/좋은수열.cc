#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 81

using namespace std;
int N;

string MIN(string A, string B) {
	if (A == "") {
		return B;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] - '0' < B[i] - '0') {
			return A;
		}
		else if (A[i] - '0' > B[i] - '0') {
			return B;
		}
		else {
			continue;
		}
	}
	return A;
}

bool isGoodseq(string S) {
	for (int pos = S.size() - 2; pos >= 0; pos -= 2) {
		int size = S.size() - pos;
		string L = S.substr(pos, size / 2);
		string R = S.substr(pos + size / 2, size / 2);
		if (L == R) {
			return false;
		}
	}
	return true;
}

void dfs(string res) {
	if (res.size() == N) {
		cout << res << "\n";
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		if (res[res.size() - 1] != (char)(i + 48)) {
			string newRes = res + to_string(i);
			if (isGoodseq(newRes)) {
				dfs(newRes);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= 3; i++) {
		dfs(to_string(i));
	}

	return 0;
}