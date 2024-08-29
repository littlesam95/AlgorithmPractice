#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
map<string, int> m;
string str;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		getline(cin, str);
		if (str == "") {
			break;
		}
		if (m.find(str) != m.end()) {
			m[str]++;
		}
		else {
			m.insert(make_pair(str, 1));
		}
	};

	int size = m.size();
	double sum = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		sum += iter->second;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << fixed;
		cout.precision(4);
		cout << iter->first << " " << (iter->second / sum) * 100 << "\n";
	}

	return 0;
}