#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int N, S = 0;
vector<int> A;
vector<int> B;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		A.push_back(number);
	}
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		B.push_back(number);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	for (int i = 0; i < N; i++) {
		S += A[i] * B[i];
	}

	cout << S << "\n";

	return 0;
}