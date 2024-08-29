#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 500001

using namespace std;
int N;
int arr[MAX];
stack<pair<int, int> > s;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		while (!s.empty()) {
			if (s.top().first < arr[i]) {
				answer += s.top().second;
				s.pop();
			}
			else {
				break;
			}
		};
		if (s.empty()) {
			s.push(make_pair(arr[i], 1));
		}
		else {
			if (s.top().first == arr[i]) {
				pair<int, int> tmp = s.top();
				s.pop();
				answer += tmp.second;
				if (!s.empty()) {
					answer++;
				}
				tmp.second++;
				s.push(tmp);
			}
			else {
				s.push(make_pair(arr[i], 1));
				answer++;
			}
		}
	}
	cout << answer << "\n";

	return 0;
}