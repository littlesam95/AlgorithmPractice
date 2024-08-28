#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
int N;
vector<string> dict;
unordered_map<char, int> m;
int answer = 0;

bool comp(pair<char, int> A, pair<char, int> B) {
	return (A.second > B.second);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		dict.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		int num = 1;
		for (int j = (dict[i].size() - 1); j >= 0; j--) {
			if (m.find(dict[i][j]) == m.end()) {
				m.insert(make_pair(dict[i][j], num));
			}
			else {
				m[dict[i][j]] += num;
			}
			num *= 10;
		}
	}
	
	vector<pair<char, int> > vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), comp);
	unordered_map<char, int> vec2m;
	int num = 9;
	for (int i = 0; i < vec.size(); i++) {
		vec2m.insert(make_pair(vec[i].first, num));
		num--;
	}

	for (int i = 0; i < N; i++) {
		int number = 0;
		int start = 1;
		for (int j = (dict[i].size() - 1); j >= 0; j--) {
			number += (vec2m[dict[i][j]] * start);
			start *= 10;
		}
		answer += number;
	}

	cout << answer << "\n";

	return 0;
}