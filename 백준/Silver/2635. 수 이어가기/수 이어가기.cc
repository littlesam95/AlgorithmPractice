#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	int arr[30001];
	int res = 0;
	int ans[30001];
	int count;
	int index;
	for (int i = 0; i <= N; i++) {
		index = 2;
		count = 2;
		arr[0] = { 0, };
		arr[0] = N;
		arr[1] = i;
		while (1) {
			arr[index] = arr[index - 2] - arr[index - 1];
			if (arr[index] < 0) {
				break;
			}
			else {
				index++;
				count++;
			}
		};
		if (res < count) {
			res = count;
			ans[0] = { 0, };
			for (int j = 0; j < res; j++) {
				ans[j] = arr[j];
			}
		}
	}

	cout << res << "\n";
	for (int i = 0; i < res; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}