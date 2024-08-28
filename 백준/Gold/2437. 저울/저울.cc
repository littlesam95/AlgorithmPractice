#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<int> chu;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		chu.push_back(number);
	}
	sort(chu.begin(), chu.end());

	int chu_sum = 0;
	for (int i = 0; i < N; i++) {
		if (chu_sum + 2 <= chu[i]) {
			break;
		}
		chu_sum += chu[i];
	}

	cout << chu_sum + 1 << "\n";

	return 0;
}