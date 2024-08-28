#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
int button[10] = { 1,1,1,1,1,1,1,1,1,1 };
int min_count = INT_MAX;

void comp(string num) {
	for (int i = 0; i < 10; i++) {
		if (button[i]) {
			string tmp = num + to_string(i);
			int tmpLen = tmp.length();
			min_count = min(min_count, abs(N - stoi(tmp)) + tmpLen);

			if (tmp.length() < 6) {
				comp(tmp);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	min_count = min(min_count, abs(100 - N));
	for (int i = 0; i < M; i++) {
		int number;
		cin >> number;
		button[number] = 0;
	}

	if (M < 10) {
		comp("");
	}

	cout << min_count << "\n";

	return 0;
}