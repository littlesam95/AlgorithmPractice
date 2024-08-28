#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
vector<int> A;

// Binary Search를 묻는 문제
int SEARCH(int left, int right, int target) {
	if (left > right) {
		return 0;
	}
	else {
		int mid = (left + right) / 2;
		if (A[mid] == target) {
			return 1;
		}
		else if (A[mid] > target) {
			return SEARCH(left, mid - 1, target);
		}
		else {
			return SEARCH(mid + 1, right, target);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		A.push_back(number);
	}

	sort(A.begin(), A.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		cout << SEARCH(0, N - 1, number) << "\n";
	}

	return 0;
}