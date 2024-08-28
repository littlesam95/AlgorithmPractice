#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
priority_queue<int, vector<int>, less<int> > pq1; // 최대힙
priority_queue<int, vector<int>, greater<int> > pq2; // 최소힙

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
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
				pq2.push(pq1_top);
				pq1.push(pq2_top);
			}
		}
		cout << pq1.top() << "\n";
	}

	return 0;
}