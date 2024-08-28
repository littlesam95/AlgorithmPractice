#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T, N;
vector<pair<int, int>> fib;

void fibo(vector<pair<int, int>>& fib) {
	for (int i = 0; i <= 40; i++) {
		if (i == 0) {
			fib.push_back(make_pair(1, 0));
		}
		else if (i == 1) {
			fib.push_back(make_pair(0, 1));
		}
		else {
			fib.push_back(make_pair(fib[i - 1].second, (fib[i - 1].first + fib[i - 1].second)));
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	fibo(fib);

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << fib[N].first << " " << fib[N].second << "\n";
	}

	return 0;
}