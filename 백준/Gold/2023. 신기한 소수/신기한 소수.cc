#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N;
vector<int> answer;

void find_answer(int number, int depth) {
	if (depth == N) {
		answer.push_back(number);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		int new_number = stoi(to_string(number) + to_string(i));
		bool flag = true;
		for (int j = 2; (j * j) <= new_number; j++) {
			if (new_number % j == 0) {
				flag = false;
			}
		}
		if (flag) {
			find_answer(new_number, depth + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	find_answer(2, 1);
	find_answer(3, 1);
	find_answer(5, 1);
	find_answer(7, 1);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}