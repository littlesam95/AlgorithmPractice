#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 41

using namespace std;
long long N, C;
long long arr[MAX];
vector<long long> vec1;
vector<long long> vec2;
long long answer = 0;

// 중간에서 만나기(Meet in the middle)
void find_sum1(long long S, long long E, long long sum) {
	if (sum > C) {
		return;
	}
	if (S == E) {
		if (sum != 0) {
			vec1.push_back(sum);
		}
		return;
	}
	find_sum1(S + 1, E, sum);
	find_sum1(S + 1, E, sum + arr[S]);
}

void find_sum2(long long S, long long E, long long sum) {
	if (sum > C) {
		return;
	}
	if (S == E) {
		if (sum != 0) {
			vec2.push_back(sum);
		}
		return;
	}
	find_sum2(S + 1, E, sum);
	find_sum2(S + 1, E, sum + arr[S]);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int div = N / 2;
	find_sum1(0, div, 0);
	find_sum2(div, N, 0);
	answer += (long long)vec1.size() + (long long)vec2.size();
	sort(vec1.begin(), vec1.end());
	for (int i = 0; i < vec2.size(); i++) {
		auto D = upper_bound(vec1.begin(), vec1.end(), C - vec2[i]) - vec1.begin();
		answer += D;
	}
	cout << answer + 1 << "\n";

	return 0;
}