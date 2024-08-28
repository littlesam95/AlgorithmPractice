#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1000001
#define LL long long
#define INF 1e9

using namespace std;
int N, K, Q, X;
unordered_map<int, int> MAP;
unordered_map<int, int>::iterator IT;
LL A[MAX];
LL Sum[MAX];

void Input() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> X;
		MAP[X]++;
	}
	cin >> Q;
}

void Settings() {
	for (IT = MAP.begin(); IT != MAP.end(); IT++) {
		int IDX = 0;
		while (IDX < N) {
			A[IDX] += IT->second;
			IDX += IT->first;
		};
	}
	for (int i = 1; i <= N; i++) {
		Sum[i] = A[i - 1] + Sum[i - 1];
	}
}

void Find_Answer() {
	while (Q--) {
		int L, R;
		cin >> L >> R;
		L++;
		R++;
		cout << Sum[R] - Sum[L - 1] << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}