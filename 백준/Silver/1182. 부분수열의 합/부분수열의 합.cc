#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int arr[21];
int flag[21] = { 0, };

void powerset(int n, int depth, int S, int& count)
{
	if (n == depth) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (flag[i] == 1) {
				sum += arr[i];
			}
		}
		if (S == sum) {
			count++;
		}
		return;
	}
	flag[depth] = 1;
	powerset(n, depth + 1, S, count);
	flag[depth] = 0;
	powerset(n, depth + 1, S, count);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int count = 0;
	if (S == 0) {
		powerset(N, 0, S, count);
		cout << count - 1;
	}
	else {
		powerset(N, 0, S, count);
		cout << count;
	}

	return 0;
}