#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> rope;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		rope.push_back(number);
	}

	sort(rope.begin(), rope.end());
	int answer = rope[0] * N;
	for (int i = 1; i < N; i++) {
		answer = (max(answer, rope[i] * (N - i)));
	}
	cout << answer << "\n";

	return 0;
}