#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
vector<int> card;
priority_queue<int, vector<int>, greater<int> > pq;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		card.push_back(number);
		pq.push(number);
	}

	while (pq.size() > 1) {
		int top1 = pq.top();
		pq.pop();
		int top2 = pq.top();
		pq.pop();
		int sum = top1 + top2;
		answer += sum;
		pq.push(sum);
	};

	pq.pop();

	cout << answer << "\n";

	return 0;
}