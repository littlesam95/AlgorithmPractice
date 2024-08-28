#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long

using namespace std;
LL A, B;

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

void Input() {
	cin >> A >> B;
}

void Settings() {
	if (A < B) {
		swap(A, B);
	}
}

void Find_Answer() {
	LL G = GCD(A, B);
	for (LL i = 0; i < G; i++) {
		cout << 1;
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}