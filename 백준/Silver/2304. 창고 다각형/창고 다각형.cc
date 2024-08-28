#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1010

using namespace std;
int N;
int arr[MAX];
int tmp_F = MAX;
int tmp_L = 0;
int tmp = 0;
int middle_idx = 0;
stack<pair<int, int> > s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int L, H;
		cin >> L >> H;
		arr[L] = H;
		if (L > tmp_L) {
			tmp_L = L;
		}
		if (L < tmp_F) {
			tmp_F = L;
		}
		if (H > arr[tmp]) {
			tmp = L;
		}
	}
	for (int i = tmp_F; i <= tmp; i++) {
		if (s.empty()) {
			s.push(make_pair(i, arr[i]));
		}
		else {
			if (s.top().second < arr[i]) {
				s.push(make_pair(i, arr[i]));
			}
		}
		answer += s.top().second;
	}
	while (!s.empty()) {
		s.pop();
	};
	for (int i = tmp_L; i > tmp; i--) {
		if (s.empty()) {
			s.push(make_pair(i, arr[i]));
		}
		else {
			if (s.top().second < arr[i]) {
				s.push(make_pair(i, arr[i]));
			}
		}
		answer += s.top().second;
	}
	cout << answer << "\n";

	return 0;
}