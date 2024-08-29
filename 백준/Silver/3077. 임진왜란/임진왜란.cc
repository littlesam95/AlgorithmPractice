#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	map<string, int> m;
	vector<string> vec;
	int N;
	cin >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m.insert(make_pair(str, (i + 1)));
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		vec.push_back(str);
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (m[vec[i]] < m[vec[j]]) {
				count++;
			}
		}
	}
	int total = (N * (N - 1)) / 2;
	cout << count << "/" << total << "\n";

	return 0;
}