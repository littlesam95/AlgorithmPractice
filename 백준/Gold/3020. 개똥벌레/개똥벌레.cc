#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
int N, H;
vector<int> bottom(100000);
vector<int> top(100000);
long long res = LLONG_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> H;
	for (int i = 0; i < (N / 2); i++) {
		cin >> bottom[i] >> top[i];
	}
	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int count = 1;
	for (int i = 1; i <= H; i++) {
		int tmp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		tmp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		if (res == tmp) {
			count++;
		}
		else if (res > tmp) {
			count = 1;
			res = tmp;
		}
	}

	cout << res << " " << count << "\n";

	return 0;
}