#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int, int> > flower;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int start = 300;
	int end = 301;
	int max_end = 0;
	int max_index = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s1, e1, s2, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		if (s1 * 100 + s2 < 301) {
			s1 = 3;
			s2 = 1;
		}
		if (e1 * 100 + e2 > 1130) {
			e1 = 12;
			e2 = 1;
		}
		flower.push_back(make_pair(s1 * 100 + s2, e1 * 100 + e2));
	}
	sort(flower.begin(), flower.end());

	for (int i = 0; i < N; i++) {
		if ((flower[i].first > start) && (flower[i].first <= end)) {
			if (max_end < flower[i].second) {
				max_end = flower[i].second;
				max_index = i;
			}
			if (flower[i].second == 1201) {
				answer++;
				end = max_end;
				break;
			}
			continue;
		}
		else {
			if (end >= max_end) {
				break;
			}
			answer++;
			start = end;
			end = max_end;
			i--;
		}
	}

	if (end == 1201) {
		cout << answer << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}