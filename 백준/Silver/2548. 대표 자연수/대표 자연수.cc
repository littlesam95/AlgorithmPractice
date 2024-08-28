#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
vector<int> vec;

int calc(int number[]) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += number[i];
	}
	return sum;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vec.push_back(tmp);
	}

	sort(vec.begin(), vec.end());

	int res = 2147483647;
	int number;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) {
				continue;
			}
			else {
				sum += abs(vec[i] - vec[j]);
			}
		}
		if (res > sum) {
			res = sum;
			number = vec[i];
		}
	}

	cout << number;

	return 0;
}