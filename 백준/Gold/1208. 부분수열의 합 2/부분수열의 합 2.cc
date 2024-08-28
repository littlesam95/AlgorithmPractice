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
int N, S;
int arr[MAX];
vector<int> vec1;
vector<int> vec2;
long long answer = 0;

// 중간에서 만나기(Meet in the middle)
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int div = N / 2;
	vec1.resize(1 << (N - div));
	for (int i = 0; i < (1 << (N - div)); i++) {
		for (int j = 0; j < (N - div); j++) {
			if (i & (1 << j)) {
				vec1[i] += arr[j];
			}
		}
	}
	sort(vec1.begin(), vec1.end());
	vec2.resize(1 << div);
	for (int i = 0; i < (1 << div); i++) {
		for (int j = 0; j < div; j++) {
			if (i & (1 << j)) {
				vec2[i] += arr[j + (N - div)];
			}
		}
	}
	sort(vec2.begin(), vec2.end(), greater<>());
	for (int i = 0; i < (1 << div); i++) {
		auto D = equal_range(vec1.begin(), vec1.end(), S - vec2[i]);
		answer += distance(D.first, D.second);
	}
	if (S != 0) {
		cout << answer << "\n";
	}
	else {
		cout << answer - 1 << "\n";
	}

	return 0;
}