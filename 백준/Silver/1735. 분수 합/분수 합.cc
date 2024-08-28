#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int A[3], B[3];

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

int LCM(int N, int M) {
	return (N * M) / GCD(N, M);
}

void Input() {
	for (int i = 0; i < 2; i++) {
		cin >> A[i] >> B[i];
	}
}

void Settings() {
	if (B[0] < B[1]) {
		swap(A[0], A[1]);
		swap(B[0], B[1]);
	}
	int L = LCM(B[0], B[1]);
	A[0] *= (L / B[0]);
	A[1] *= (L / B[1]);
	A[2] = A[0] + A[1];
	B[2] = L;
	int G = GCD(B[2], A[2]);
	A[2] /= G;
	B[2] /= G;
}

void Find_Answer() {
	cout << A[2] << " " << B[2] << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}