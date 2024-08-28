#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int K, N;
long long top = 0;
long long arr[101];
priority_queue<long long, vector<long long>, greater<long long> > pq;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	for (int i = 0; i < N; i++) {
		top = pq.top();
		pq.pop();
		for (int j = 0; j < K; j++) {
			long long val = top * arr[j];
			pq.push(val);
			if (top % arr[j] == 0) { // 중복 X
				break;
			}
		}
	}
	cout << top << "\n";

	return 0;
}