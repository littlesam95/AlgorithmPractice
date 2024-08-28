#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
vector<long long> expect;
long long answer = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		expect.push_back(number);
	}
	sort(expect.begin(), expect.end());
	for (int i = 1; i <= N; i++) {
		if (expect[i - 1] != i) {
			answer += abs(expect[i - 1] - i);
		}
	}

	cout << answer << "\n";

	return 0;
}