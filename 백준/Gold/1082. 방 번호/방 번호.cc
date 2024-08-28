#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51

using namespace std;
int N, M;
vector<int> vec;
string dp[MAX];
string answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = "#";
	}
}

string comp(string A, string B) {
	if (A.size() == B.size()) {
		bool flag = true;
		for (int i = 0; i < A.size(); i++) {
			if (A[i] - '0' < B[i] - '0') {
				flag = true;
				break;
			}
			else if (A[i] - '0' > B[i] - '0') {
				flag = false;
				break;
			}
			if (i == A.size() - 1) {
				if (A[i] - '0' == B[i] == '0') {
					flag = true;
				}
			}
		}
		if (flag) {
			return B;
		}
		else {
			return A;
		}
	}
	else if (A.size() < B.size()) {
		return B;
	}
	else {
		return A;
	}
}

string dfs(int X) {
	if (dp[X] != "#") {
		return dp[X];
	}
	dp[X] = "";
	for (int i = 0; i < vec.size(); i++) {
		if (X - vec[i] >= 0) {
			if (X == M) {
				if ((i == 0) && (X - vec[i] > 0)) {
					continue;
				}
			}
			dp[X] = comp(dp[X], to_string(i) + dfs(X - vec[i]));
		}
	}
	return dp[X];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		vec.push_back(P);
	}
	cin >> M;
	answer = dfs(M);
	if (answer != "") {
		cout << answer << "\n";
	}
	else {
		cout << "0" << "\n";
	}

	return 0;
}