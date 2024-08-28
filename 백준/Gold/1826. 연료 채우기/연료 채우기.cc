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
	int dist, oil;
};

struct comp1 {
	bool operator()(Info &A, Info &B) {
		return (A.dist > B.dist);
	}
};

struct comp2 {
	bool operator()(Info &A, Info &B) {
		return (A.oil < B.oil);
	}
};

int N, L, P;
Info tmp;
priority_queue<Info, vector<Info>, comp1> pq1;
priority_queue<Info, vector<Info>, comp2> pq2;
long long answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		tmp.dist = A;
		tmp.oil = B;
		pq1.push(tmp);
	}
	cin >> L >> P;
	while (P < L) {
		while ((!pq1.empty()) && (pq1.top().dist <= P)) {
			tmp.dist = pq1.top().dist;
			tmp.oil = pq1.top().oil;
			pq2.push(tmp);
			pq1.pop();
		};
		if (pq2.empty()) {
			answer = -1;
			break;
		}
		int O = pq2.top().oil;
		pq2.pop();
		P += O;
		answer++;
	};

	cout << answer << "\n";

	return 0;
}