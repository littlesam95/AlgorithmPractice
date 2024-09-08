#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		vector<string> vec;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			vec.push_back(str);
		}

		unordered_map<string, int> m;
		for (int i = 0; i < n; i++) {
			m[vec[i]] = 1;
		}

		bool b = true;
		for (int i = 0; i < n; i++) {
			string phone = "";
			for (int j = 0; j < vec[i].size(); j++) {
				phone += vec[i][j];
				if ((m[phone]) && (phone != vec[i])) {
					b = false;
					break;
				}
			}
			if (!b) {
				break;
			}
		}
		if (b) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	};

	return 0;
}