#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51

using namespace std;
int N;
long long height[MAX];
int arr[MAX];
int answer = 0;

int CCW(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C) {
	long long op = A.first * B.second + B.first * C.second + C.first * A.second;
	op -= (A.second * B.first + B.second * C.first + C.second * A.first);
	if (op > 0) {
		return 1;
	}
	else if (op == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

int intersect(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C, pair<long long, long long> D) {
	int ab = CCW(A, B, C) * CCW(A, B, D);
	int cd = CCW(C, D, A) * CCW(C, D, B);
	if ((ab == 0) && (cd == 0)) {
		if (A > B) {
			swap(A, B);
		}
		if (C > D) {
			swap(C, D);
		}
		return ((A <= D) && (C <= B));
	}
	return ((ab <= 0) && (cd <= 0));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> height[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			pair<long long, long long> A, B;
			A.first = i;
			A.second = height[i];
			B.first = j;
			B.second = height[j];
			bool flag = true;
			if (i < j) {
				for (int k = i + 1; k < j; k++) {
					pair<long long, long long> C, D;
					C.first = k;
					C.second = height[k];
					D.first = k;
					D.second = 0;
					if (intersect(A, B, C, D) == 1) {
						flag = false;
						break;
					}
				}
			}
			else if (i > j) {
				for (int k = j + 1; k < i; k++) {
					pair<long long, long long> C, D;
					C.first = k;
					C.second = height[k];
					D.first = k;
					D.second = 0;
					if (intersect(A, B, C, D) == 1) {
						flag = false;
						break;
					}
				}
			}
			if (flag) {
				arr[i]++;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		answer = max(answer, arr[i]);
	}
	cout << answer << "\n";

	return 0;
}