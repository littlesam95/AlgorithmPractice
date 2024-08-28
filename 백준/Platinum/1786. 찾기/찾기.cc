#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
string T, P;
vector<int> fail;
int N, M;
vector<int> answer;

void make_fail() {
	M = P.size();
	fail.resize(M, 0);
	for (int i = 1, j = 0; i < M; i++) {
		while ((j > 0) && (P[i] != P[j])) {
			j = fail[j - 1];
		};
		if (P[i] == P[j]) {
			j++;
			fail[i] = j;
		}
	}
}

int kmp() {
	make_fail();
	N = T.size();
	int res = 0;
	for (int i = 0, j = 0; i < N; i++) {
		while ((j > 0) && (T[i] != P[j])) {
			j = fail[j - 1];
		};
		if (T[i] == P[j]) {
			if (j == M - 1) {
				answer.push_back(i - M + 1);
				res++;
				j = fail[j];
			}
			else {
				j++;
			}
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	getline(cin, T);
	getline(cin, P);
	int answer_size = kmp();
	sort(answer.begin(), answer.end());
	cout << answer_size << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] + 1 << " ";
	}

	return 0;
}