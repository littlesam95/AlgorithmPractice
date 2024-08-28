#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, S, L, R;
int arr[MAX];
int answer = INT_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	L = R = 0;
	int sum = 0;
	while (1) {
		if (sum >= S) {
			sum -= arr[L];
			L++;
			int len = R - L + 1;
			answer = min(answer, len);
		}
		else if (R == N) {
			break;
		}
		else {
			sum += arr[R];
			R++;
		}
	};
	if (answer != INT_MAX) {
		cout << answer << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	return 0;
}