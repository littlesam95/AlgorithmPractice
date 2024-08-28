#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	};

	cout << q.front();

	return 0;
}