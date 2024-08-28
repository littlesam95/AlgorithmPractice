#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string paper, search;
	getline(cin, paper);
	getline(cin, search);

	int lenP = paper.length();
	int lenS = search.length();
	int index = 0;
	int count = 0;
	while (index < lenP) {
		bool b = false;
		if (search == paper.substr(index, lenS)) {
			count++;
			b = true;
		}
		if (b) {
			index += lenS;
		}
		else {
			index++;
		}
	}

	cout << count;

	return 0;
}