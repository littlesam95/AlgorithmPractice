#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
vector<unsigned long long> vec;
vector<int> v = { 9,8,7,6,5,4,3,2,1,0 };

void calc(vector<unsigned long long>& vec, int N) {
	for (int i = 1; i < (1 << 10); i++) {
		unsigned long long sum = 0;
		for (int j = 0; j < 10; j++) {
			if (i&(1 << j)) {
				sum = sum * 10 + v[j];
			}
		}
		vec.push_back(sum);
	}
	sort(vec.begin(), vec.end());
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	if (N <= 1023) {
		calc(vec, N);
		cout << vec[N - 1];
	}
	else {
		cout << -1;
	}

	return 0;
}