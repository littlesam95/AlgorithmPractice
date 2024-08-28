#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N;
int arr[1004001];
int res;

bool pelindrome(string str) {
	int left = 0;
	int right = str.length() - 1;
	bool b = true;
	while (left < right) {
		if (str[left] != str[right]) {
			b = false;
			break;
		}
		left++;
		right--;
	};
	return b;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	arr[0] = -1;
	arr[1] = -1;
	for (int i = 2; i < 1004001; i++) {
		arr[i] = i;
	}
	int end = floor(sqrt(1004000));
	for (int i = 2; i <= end; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i * i; j <= 1004000; j += i) {
			arr[j] = 0;
		}
	}

	cin >> N;
	int number = N;
	res = N;
	while (1) {
		if (arr[number] >= 0) {
			if (arr[number] != 0) {
				if (pelindrome(to_string(number))) {
					res = number;
					break;
				}
				else {
					number++;
					continue;
				}
			}
			else {
				number++;
				continue;
			}
		}
		else {
			number++;
			continue;
		}
	};

	cout << res << "\n";

	return 0;
}