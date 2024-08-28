#include <iostream>
#include <string>
#include <string.h>
#include <deque>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int get_array_size(char arr[]) {
	return sizeof arr / sizeof arr[0];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	deque<int> q;
	vector<int> res;
	for (int i = N; i >= 1; i--) {
		q.push_front(i);
	}
	int len = q.size();
	while (len > 0) {
		for (int i = 0; i < (K - 1); i++) {
			q.push_back(q.front());
			q.pop_front();
		}
		res.push_back(q.front());
		q.pop_front();
		len--;
	};

	int count = res.size();
	cout << "<";
	for (int i = 0; i < count; i++) {
		if (i == count - 1) {
			cout << res[i];
		}
		else {
			cout << res[i] << ", ";
		}
	}
	cout << ">";

	return 0;

}