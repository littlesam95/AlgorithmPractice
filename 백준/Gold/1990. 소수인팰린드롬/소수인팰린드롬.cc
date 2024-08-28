#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 10000001

using namespace std;
int A, B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	if (B >= MAX) {
		B = MAX - 1;
	}
	for (int i = A; i <= B; i++) {
		string N = to_string(i);
		string newN = N;
		reverse(N.begin(), N.end());
		if (N == newN) {
			bool Flag = true;
			for (int j = 2; j <= sqrt(i); j++) {
				if (i % j == 0) {
					Flag = false;
					break;
				}
			}
			if (Flag) {
				cout << i << "\n";
			}
		}
	}
	cout << -1 << "\n";

	return 0;
}