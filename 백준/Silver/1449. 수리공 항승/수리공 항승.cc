#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;
vector<int> water;
bool tape[1001] = { false, };
int answer = 0;

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		water.push_back(number);
	}
	sort(water.begin(), water.end());
	for (int i = 0; i < water.size(); i++) {
		if (!tape[water[i]]) {
			for (int j = water[i]; j < min(water[i] + L, 1001); j++) {
				tape[j] = true;
			}
			answer++;
		}
	}

	cout << answer << "\n";

	return 0;
}