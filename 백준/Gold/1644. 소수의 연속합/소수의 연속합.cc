#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[4000001];
bool visited[10001];
int answer = 0;

void init() {
	for (int i = 2; i <= 4000000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(4000000); i++) {
		if (arr[i] != 0) {
			for (int j = i * i; j <= 4000000; j += i) {
				arr[j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (arr[i] != 0) {
			int tmp = 0;
			for (int j = i; j <= N; j++) {
				if (arr[j] != 0) {
					tmp += j;
				}
				if (tmp == N) {
					answer++;
					break;
				}
				else if (tmp > N) {
					break;
				}
			}
		}
	}
	cout << answer << "\n";

	return 0;
}