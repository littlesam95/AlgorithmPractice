#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
long long N, P, Q;
map<long long, long long> m;

long long calc(long long N) {
	if (m.count(N)) {
		return m[N];
	}
	else {
		return m[N] = calc(N / P) + calc(N / Q);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P >> Q;
	m.insert(make_pair(0, 1));
	cout << calc(N) << "\n";

	return 0;
}