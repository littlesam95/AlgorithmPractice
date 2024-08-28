#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		char number[5];
		bool b = true;
		sprintf(number, "%d", i);
		if ((i >= 1) && (i <= 99)) {
			count++;
		}
		else if ((i >= 100) && (i <= 999)) {
			for (int j = 0; j < 1; j++) {
				if ((number[j + 1] - number[j]) != (number[j + 2] - number[j + 1])) {
					b = false;
					break;
				}
			}
			if (b) {
				count++;
			}
		}
		else if (i == 1000) {
			continue;
		}
	}

	cout << count;

	return 0;

}