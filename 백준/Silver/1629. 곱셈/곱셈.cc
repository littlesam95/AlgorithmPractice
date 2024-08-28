#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
long long A, B, C;
long long answer = 0;

long long POW(long long X, long long M) {
	if (M == 0) {
		return 1;
	}
	else if (M == 1) {
		return X;
	}
	if ((M % 2) > 0) {
		return POW(X, M - 1) * X;
	}
	long long H = POW(X, M / 2);
	H %= C;
	return (H * H) % C;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	cout << POW(A, B) % C << "\n";

	return 0;
}