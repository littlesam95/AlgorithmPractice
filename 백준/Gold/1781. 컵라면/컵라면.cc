#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int deadline, noodle;
};

bool comp(Info A, Info B) {
	return (A.deadline < B.deadline);
}

int N;
Info tmp;
vector<Info> vec;
priority_queue<int, vector<int>, greater<int> > pq;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		tmp.deadline = X;
		tmp.noodle = Y;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), comp);
	for (int i = 0; i < vec.size(); i++) {
		if (pq.empty()) {
			pq.push(vec[i].noodle);
		}
		else {
			if (pq.size() < vec[i].deadline) {
				pq.push(vec[i].noodle);
			}
			else {
				if (pq.top() < vec[i].noodle) {
					pq.pop();
					pq.push(vec[i].noodle);
				}
			}
		}
	}
	while (!pq.empty()) {
		answer += pq.top();
		pq.pop();
	};

	cout << answer << "\n";

	return 0;
}