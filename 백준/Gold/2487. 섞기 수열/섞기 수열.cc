#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 20001

using namespace std;
int N;
int S[MAX];
bool visited[MAX];
int Answer = 1;

// 순열 사이클 분할(Permutation Cycle Decomposition)
int GCD(int N, int M) {
	while (1) {
		int R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			int K = 0;
			for (int j = i; !visited[j]; j = S[j]) {
				visited[j] = true;
				K++;
			}
			Answer = Answer / GCD(Answer, K) * K;
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}