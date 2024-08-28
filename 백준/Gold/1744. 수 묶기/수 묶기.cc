#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<int> perm;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		perm.push_back(number);
	}
	priority_queue<int, vector<int>, greater<int> > minus;
	priority_queue<int, vector<int>, less<int> > zero;
	priority_queue<int, vector<int>, less<int> > one;
	priority_queue<int, vector<int>, less<int> > plus;
	for (int i = 0; i < N; i++) {
		if (perm[i] > 1) {
			plus.push(perm[i]);
		}
		else if (perm[i] == 1) {
			one.push(perm[i]);
		}
		else if (perm[i] == 0) {
			zero.push(perm[i]);
		}
		else {
			minus.push(perm[i]);
		}
	}
	while (!plus.empty()) {
		if (plus.size() == 1) {
			int top = plus.top();
			answer += top;
			plus.pop();
		}
		else {
			int top1 = plus.top();
			plus.pop();
			int top2 = plus.top();
			plus.pop();
			long long mul = top1 * top2;
			answer += mul;
		}
	};
	while (!one.empty()) {
		int top = one.top();
		one.pop();
		answer += top;
	}
	while (minus.size() > 1) {
		int top1 = minus.top();
		minus.pop();
		int top2 = minus.top();
		minus.pop();
		long long mul = top1 * top2;
		answer += mul;
	};
	if ((zero.empty()) && (minus.size() == 1)) {
		int top = minus.top();
		minus.pop();
		answer += top;
	}

	cout << answer << "\n";

	return 0;
}