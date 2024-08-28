#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 46
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int K;
int A[MAX], B[MAX];

void init() {
	B[1] = 1;
	A[2] = 1;
	B[2] = 1;
	for (int i = 3; i < MAX; i++) {
		A[i] = A[i - 1] + A[i - 2];
		B[i] = B[i - 1] + B[i - 2];
	}
}

void input() {
	cin >> K;
}

void find_Answer() {
	cout << A[K] << " " << B[K] << "\n";
}

int main() {
	FASTIO
	init();
	input();
	find_Answer();

	return 0;
}