#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int res = 0;

int main() {
	int L, n;
	cin >> L;
	vector<int> vec(L);
	for (int i = 0; i < L; i++) {
		cin >> vec[i];
	}
	vec.push_back(0);
	sort(vec.begin(), vec.end());
	cin >> n;

	int start, end;
	bool com = true;
	for (int i = 1; i < (L + 1); i++) {
		if (vec[i] == n) {
			com = false;
		}
		else if (vec[i] > n) {
			start = vec[i - 1] + 1;
			end = vec[i] - 1;
			break;
		}
	}

	if (com) {
		res = (n - start)*(end - n + 1) + (end - n);
	}

	cout << res;

	return 0;
}