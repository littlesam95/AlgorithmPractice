#include <iostream>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <string.h>

using namespace std;
int N;
vector<int> vec;
deque<int> q;
deque<int> qindex;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int number;
		cin >> number;
		q.push_back(number);
		qindex.push_back(i + 1);
	}

	int cursor = 1;
	while (!q.empty()) {
		int count;
		if (cursor == 1) {
			count = q.front();
			if (q.front() >= 0) {
				cursor = 1;
			}
			else {
				cursor = 0;
			}
			vec.push_back(qindex.front());
			q.pop_front();
			qindex.pop_front();
		}
		else if (cursor == 0) {
			count = q.back();
			if (q.back() >= 0) {
				cursor = 1;
			}
			else {
				cursor = 0;
			}
			vec.push_back(qindex.back());
			q.pop_back();
			qindex.pop_back();
		}
		if (cursor == 1) {
			if (q.size() > 1) {
				for (int i = 0; i < (count - 1); i++) {
					q.push_back(q.front());
					q.pop_front();
					qindex.push_back(qindex.front());
					qindex.pop_front();
				}
			}
		}
		else if (cursor == 0) {
			if (q.size() > 1) {
				for (int i = 0; i < abs(count) - 1; i++) {
					q.push_front(q.back());
					q.pop_back();
					qindex.push_front(qindex.back());
					qindex.pop_back();
				}
			}
		}
	};

	int size = vec.size();
	for (int i = 0; i < size; i++) {
		cout << vec[i] << " ";
	}

	return 0;
}