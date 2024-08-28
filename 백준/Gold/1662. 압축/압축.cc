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
string S;
int visited[MAX];
stack<int> s;

long long dfs(int L, int R) {
	long long res = 0;
	for (int i = L; i < R; i++) {
		if (S[i] == '(') {
			long long tmp = S[i - 1] - '0';
			res += tmp * dfs(i + 1, visited[i]) - 1;
			i = visited[i];
			continue;
		}
		res++;
	}
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			s.push(i);
		}
		else if (S[i] == ')') {
			visited[s.top()] = i;
			s.pop();
		}
	}

	cout << dfs(0, S.size()) << "\n";

	return 0;
}