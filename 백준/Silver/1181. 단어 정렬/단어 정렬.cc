#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

bool COMP(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else {
		return a.size() < b.size();
	}
}

int main() {
	int N;
	cin >> N;

	vector<string> str;
	string tmp;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cin.ignore();
		}
		getline(cin, tmp);
		str.push_back(tmp);
	}

	sort(str.begin(), str.end(), COMP);

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			cout << str[i] << "\n";
		}
		else if (i > 0) {
			if (str[i - 1] != str[i]) {
				cout << str[i] << "\n";
			}
		}
	}

	return 0;
}