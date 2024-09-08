#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long

using namespace std;
LL N, A, B;

LL GCD(LL N, LL M) {
	while (1) {
		LL R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

LL LCM(LL N, LL M) {
	return (N * M) / GCD(N, M);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		cout << LCM(A, B) << "\n";
	}
}

int main() {
	FASTIO
	Input();

	return 0;
}