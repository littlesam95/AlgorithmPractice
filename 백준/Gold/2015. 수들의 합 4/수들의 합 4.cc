#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 200001
#define INF 2e9

using namespace std;
int N, K;
int Sum_Arr[MAX];
map<int, long long> m;
long long answer = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		Sum_Arr[i] = Sum_Arr[i - 1] + tmp;
	}
	for (int i = 1; i <= N; i++) {
		if (Sum_Arr[i] == K) {
			answer++;
		}
		answer += m[Sum_Arr[i] - K];
		m[Sum_Arr[i]]++;
	}
	cout << answer << "\n";

	return 0;
}