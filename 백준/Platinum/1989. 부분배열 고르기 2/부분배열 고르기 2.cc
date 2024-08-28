#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100010

using namespace std;
int N;
long long A[MAX];
stack<pair<int, pair<long long, int> > > s;
long long tmp;
int tmp_F, tmp_S;
long long answer = 0;
pair<int, int> answer_p;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	answer_p.first = 1;
	answer_p.second = 1;
	s.push(make_pair(0, make_pair(0, 0)));
	for (int i = 1; i <= N + 1; i++) {
		tmp = 0;
		if (i <= N) {
			cin >> A[i];
		}
		else if (i == N + 1) {
			tmp_S = s.top().second.second;
		}
		if (s.top().first == 0) {
			tmp += A[i];
			s.push(make_pair(i, make_pair(tmp, (tmp > A[i]) ? tmp_F : i)));
		}
		else {
			if (A[s.top().first] > A[i]) {
				while (A[s.top().first] > A[i]) {
					tmp += s.top().second.first;
					tmp_F = s.top().second.second;
					if (answer < tmp * A[s.top().first]) {
						answer_p.first = tmp_F;
						if (i <= N) {
							answer_p.second = i - 1;
						}
						else if (i == N + 1) {
							answer_p.second = tmp_S;
						}
					}
					answer = max(answer, tmp * A[s.top().first]);
					s.pop();
					if (s.top().first == 0) {
						break;
					}
				};
				tmp += A[i];
				s.push(make_pair(i, make_pair(tmp, (tmp > A[i]) ? tmp_F : i)));
			}
			else {
				tmp += A[i];
				s.push(make_pair(i, make_pair(tmp, (tmp > A[i]) ? tmp_F : i)));
			}
		}
	}
	cout << answer << "\n";
	cout << answer_p.first << " " << answer_p.second << "\n";

	return 0;
}