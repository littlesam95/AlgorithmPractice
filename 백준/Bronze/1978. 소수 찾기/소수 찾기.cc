#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
int N;
vector<int> A;

int SEARCH(vector<int> A) {
	int result = 0;
	int number;
	bool res;
	for (int i = 0; i < N; i++) {
		res = false;
		if (A[i] > 2) {
			if ((A[i] % 2) != 0) {
				number = A[i];
				do {
					number--;
					if (A[i] % number == 0) {
						res = true;
					}
				} while (!res);
				if (number == 1) {
					result++;
				}
			}
		}
		if (A[i] == 2) {
			result++;
		}
	}

	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		A.push_back(number);
	}

	cout << SEARCH(A);

	return 0;
}