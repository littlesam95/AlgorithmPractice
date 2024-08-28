#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
string str;
string arr[51];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	int len = str.length();
	string tmp = "";
	int index = 0;
	for (int i = 0; i < len; i++) {
		if ((str.substr(i, 1) == "+") || (str.substr(i, 1) == "-")) {
			arr[index++] = tmp;
			tmp = "";
			arr[index++] = str.substr(i, 1);
		}
		else {
			tmp += str.substr(i, 1);
			if (i == len - 1) {
				arr[index++] = tmp;
			}
		}
	}

	queue<int> q;
	int sum = stoi(arr[0]);
	bool b = true;
	for (int i = 1; i < index; i += 2) {
		if ((arr[i] == "-") && b) {
			b = false;
		}
		if (b) {
			sum += stoi(arr[i + 1]);
		}
		else {
			sum -= stoi(arr[i + 1]);
		}
	}

	cout << sum << "\n";

	return 0;
}