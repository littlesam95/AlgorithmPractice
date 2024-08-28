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
	int S, E;
};

int N, A, B;
int Lsize = 1;
Info tmp;
vector<Info> vec;
priority_queue<int, vector<int>, greater<int> > pq;
int answer = 1;

bool comp(Info A, Info B) {
	if (A.S == B.S) {
		return (A.E < B.E);
	}
	return (A.S < B.S);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
		if (X > Y) {
			swap(X, Y);
		}
		tmp.S = X;
		tmp.E = Y;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), comp);
	for (int i = 0; i < vec.size(); i++) {
		if (pq.empty()) {
			pq.push(vec[i].E);
		}
		else {
			while ((!pq.empty()) && (pq.top() <= vec[i].S)) {
				pq.pop();
			};
			pq.push(vec[i].E);
			answer = max(answer, (int)pq.size());
		}
	}
	cout << answer << "\n";

	return 0;
}