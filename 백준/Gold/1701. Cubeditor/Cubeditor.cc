#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 5001

using namespace std;
string S;
vector<int> fail;
int N;
int answer = 0;

// KMP 알고리즘을 사용하여 시간 단축
void make_fail(string s) {
	N = s.size();
	fail.clear();
	fail.resize(N, 0);
	for (int i = 1, j = 0; i < N; i++) {
		while ((j > 0) && (s[i] != s[j])) {
			j = fail[j - 1];
		};
		if (s[i] == s[j]) {
			j++;
			fail[i] = j;
		}
	}
}

/*
void kmp() {
	make_fail();
	for (int i = 0, j = 0; i < N; i++) {
		while ((j > 0) && (S[i] != P[j])) {
			j = fail[j - 1];
		};
		if (S[i] == P[j]) {
			if (j == M - 1) {
				answer++;
				break;
			}
			else {
				j++;
			}
		}
	}
}
*/

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		make_fail(S.substr(i));
		for (int j = 0; j < S.size() - i; j++) {
			answer = max(answer, fail[j]);
		}
	}
	cout << answer << "\n";

	return 0;
}