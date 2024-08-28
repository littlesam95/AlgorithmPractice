#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int X;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X;
	while (X > 0) {
		if (X % 2 == 1) {
			answer++;
		}
		X /= 2;
	}
	cout << answer << "\n";

	return 0;
}