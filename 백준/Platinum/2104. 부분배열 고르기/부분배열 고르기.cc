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
stack<pair<int, long long> > s;
long long tmp;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	s.push(make_pair(0, 0));
	for (int i = 1; i <= N + 1; i++) {
		tmp = 0;
		if (i <= N) {
			cin >> A[i];
		}
		if (s.top().first == 0) {
			tmp += A[i];
			s.push(make_pair(i, tmp));
		}
		else {
			if (A[s.top().first] > A[i]) {
				while (A[s.top().first] > A[i]) {
					tmp += s.top().second;
					answer = max(answer, tmp * A[s.top().first]);
					s.pop();
					if (s.top().first == 0) {
						break;
					}
				};
				tmp += A[i];
				s.push(make_pair(i, tmp));
			}
			else {
				tmp += A[i];
				s.push(make_pair(i, tmp));
			}
		}
	}
	cout << answer << "\n";

	return 0;
}