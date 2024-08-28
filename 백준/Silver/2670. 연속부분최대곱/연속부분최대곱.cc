#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
double arr[10001];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	double res = 0;
	for (int i = 0; i < N; i++) {
		double mul = 0;
		for (int j = i; j < N; j++) {
			if (j == i) {
				mul += arr[j];
				if (res < mul) {
					res = mul;
				}
			}
			else {
				mul *= arr[j];
				if (res < mul) {
					res = mul;
				}
			}
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << round(res * 1000) / 1000;

	return 0;
}