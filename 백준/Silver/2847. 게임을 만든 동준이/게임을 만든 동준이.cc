#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> score;
int answer = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		score.push_back(number);
	}
	for (int i = N - 2; i >= 0; i--) {
		if (score[i] >= score[i + 1]) {
			int right_score = score[i + 1] - 1;
			int diff = score[i] - right_score;
			score[i] = right_score;
			answer += diff;
		}
	}

	cout << answer << "\n";

	return 0;
}