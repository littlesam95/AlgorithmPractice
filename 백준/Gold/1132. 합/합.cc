#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;
int N;
vector<string> vec;
unordered_map<char, long long> m;
bool zero_arr[10] = { false, };
long long answer = 0;

bool comp(pair<char, long long> A, pair<char, long long> B) {
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
		vec.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int size = vec[i].size() - 1;
		long long start = 1;
		for (int j = size; j >= 0; j--) {
			if (m.find(vec[i][j]) == m.end()) {
				m.insert(make_pair(vec[i][j], start));
			}
			else {
				m[vec[i][j]] += start;
			}
			if (j == 0) {
				zero_arr[int(vec[i][j]) - 65] = true;
			}
			start *= 10;
		}
	}
	vector<pair<char, long long> > new_m(m.begin(), m.end());
	sort(new_m.begin(), new_m.end(), comp);
	char point;
	if (new_m.size() == 10) {
		long long front_num = LLONG_MAX;
		for (int i = 0; i < 10; i++) {
			if (!zero_arr[int(new_m[i].first) - 65]) {
				if (front_num > new_m[i].second) {
					front_num = new_m[i].second;
					point = new_m[i].first;
				}
			}
		}
		int start = 9;
		for (int i = 0; i < new_m.size(); i++) {
			if (new_m[i].first != point) {
				answer += (new_m[i].second * start);
				start--;
			}
		}
	}
	else if (new_m.size() < 10) {
		int start = 9;
		for (int i = 0; i < new_m.size(); i++) {
			answer += (new_m[i].second * start);
			start--;
		}
	}

	cout << answer << "\n";

	return 0;
}