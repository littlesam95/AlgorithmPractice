#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int L;
string S;
vector<int> fail;
int answer;

void make_fail() {
	fail.clear();
	fail.resize(L, 0);
	for (int i = 1, j = 0; i < L; i++) {
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

	cin >> L;
	cin >> S;
	make_fail();
	answer = L - fail[L - 1];
	cout << answer << "\n";

	return 0;
}