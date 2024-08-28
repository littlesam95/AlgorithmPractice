#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int T, M;
priority_queue<int, vector<int>, less<int> > pq1; // 최대힙
priority_queue<int, vector<int>, greater<int> > pq2; // 최소힙
int answer;
vector<int> answer_vec;

void init() {
	while (!pq1.empty()) {
		pq1.pop();
	};
	while (!pq2.empty()) {
		pq2.pop();
	};
	answer = 0;
	answer_vec.clear();
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> M;
		for (int i = 0; i < M; i++) {
			int X;
			cin >> X;
			if (pq1.size() > pq2.size()) {
				pq2.push(X);
			}
			else {
				pq1.push(X);
			}
			if ((!pq1.empty()) && (!pq2.empty())) {
				if (pq1.top() > pq2.top()) {
					int pq1_top = pq1.top();
					int pq2_top = pq2.top();
					pq1.pop();
					pq2.pop();
					pq1.push(pq2_top);
					pq2.push(pq1_top);
				}
			}
			if ((pq1.size() + pq2.size()) % 2 == 1) {
				answer_vec.push_back(pq1.top());
			}
		}
		cout << answer_vec.size() << "\n";
		for (int i = 0; i < answer_vec.size(); i++) {
			cout << answer_vec[i];
			if ((i > 0) && (i % 9 == 0)) {
				cout << "\n";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	};
    
	return 0;
}