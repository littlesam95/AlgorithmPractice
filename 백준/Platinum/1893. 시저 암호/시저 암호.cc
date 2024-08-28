#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 63

using namespace std;
int N;
string A, W, S;
vector<int> fail;
int D, E;
vector<int> answer;

void make_fail(string w) {
	E = w.size();
	fail.clear();
	fail.resize(E, 0);
	for (int i = 1, j = 0; i < E; i++) {
		while ((j > 0) && (w[i] != w[j])) {
			j = fail[j - 1];
		};
		if (w[i] == w[j]) {
			j++;
			fail[i] = j;
		}
	}
}

bool kmp(string w) {
	make_fail(w);
	D = S.size();
	bool flag = false;
	for (int i = 0, j = 0; i < D; i++) {
		while ((j > 0) && (S[i] != w[j])) {
			j = fail[j - 1];
		};
		if (S[i] == w[j]) {
			if (j == E - 1) {
				if (!flag) {
					flag = true;
					j = fail[j];
				}
				else {
					flag = false;
					break;
				}
			}
			else {
				j++;
			}
		}
	}
	return flag;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) {
		answer.clear();
		cin >> A;
		cin >> W;
		cin >> S;
		for (int X = 0; X < A.size(); X++) {
			string new_W = "";
			bool Z = true;
			for (int i = 0; i < W.size(); i++) {
				int idx = -1;
				for (int j = 0; j < A.size(); j++) {
					if (A[j] == W[i]) {
						idx = j;
						break;
					}
				}
				if (idx == -1) {
					Z = false;
					break;
				}
				else {
					if (idx + X < A.size()) {
						new_W += A[idx + X];
					}
					else {
						new_W += A[(idx + X) % A.size()];
					}
				}
			}
			if (Z) {
				bool flag = kmp(new_W);
				if (flag) {
					answer.push_back(X);
				}
			}
		}
		if (answer.size() == 0) {
			cout << "no solution" << "\n";
		}
		else if (answer.size() == 1) {
			cout << "unique: " << answer[0] << "\n";
		}
		else if (answer.size() >= 2) {
			cout << "ambiguous: ";
			for (int k = 0; k < answer.size(); k++) {
				cout << answer[k] << " ";
			}
			cout << "\n";
		}
	};

	return 0;
}