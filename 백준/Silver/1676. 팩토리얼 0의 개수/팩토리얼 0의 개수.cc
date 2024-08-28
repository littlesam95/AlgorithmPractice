#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
int N;

void calc(int N, int& count) {
	for (int i = 2; i <= N; i++) {
		if ((i % 5 == 0) && (i % 25 != 0)) {
			count++;
		}
		else if ((i % 25 == 0) && (i % 125 != 0)) {
			count += 2;
		}
		else if ((i % 125 == 0)) {
			count += 3;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int count = 0;

	cin >> N;
	calc(N, count);
	cout << count;

	return 0;
}