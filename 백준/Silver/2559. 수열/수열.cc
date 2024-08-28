#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001
#define INF 2e9

using namespace std;
int N, K;
int Arr[MAX];
int tmp = 0;
int answer = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}
	for (int i = 0; i < K; i++) {
		tmp += Arr[i];
	}
	answer = tmp;
	for (int i = K; i < N; i++) {
		tmp += (Arr[i] - Arr[i - K]);
		answer = max(answer, tmp);
	}

	cout << answer << "\n";

	return 0;
}