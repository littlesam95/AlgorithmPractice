#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
string S;
vector<int> fail;
int M;
int answer;

void make_fail() {
	M = S.size();
	fail.clear();
	fail.resize(M, 0);
	for (int i = 1, j = 0; i < M; i++) {
		while ((j > 0) && (S[i] != S[j])) {
			j = fail[j - 1];
		};
		if (S[i] == S[j]) {
			j++;
			fail[i] = j;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> S;
		if (S == ".") {
			break;
		}
		make_fail();
		if (M % (M - fail[M - 1]) != 0) { // 접두사와 접미사가 모두 될 수 있는 부분문자열이 있는 경우
			// fail[S.length() - 1] > 1임에도 반복되는 문자열로 나눠지지 않는 경우
			answer = 1;
		}
		else {
			answer = M / (M - fail[M - 1]);
		}
		cout << answer << "\n";
	};

	return 0;
}