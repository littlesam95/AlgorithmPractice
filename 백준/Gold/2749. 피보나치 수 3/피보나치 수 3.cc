#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MOD 1000000

using namespace std;
long long N;
vector<vector<long long> > M, answer;

// 피보나치의 점화식을 행렬의 곱셈을 통해 분할 정복으로 풀이
vector<vector<long long> > Calc(vector<vector<long long> > A, vector<vector<long long> > B) {
	vector<vector<long long> > Res(2, vector<long long>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				Res[i][j] = Res[i][j] + (A[i][k] * B[k][j]);
			}
			Res[i][j] %= (long long)MOD;
		}
	}
	return Res;
}

void Solution() {
	while (N > 0) {
		if (N % 2 == 1) {
			answer = Calc(answer, M);
		}
		M = Calc(M, M);
		N /= 2;
	};
	cout << answer[0][1] << "\n";
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	answer = { {1,0},{0,1} };
	M = { {1,1},{1,0} };
	Solution();

	return 0;
}