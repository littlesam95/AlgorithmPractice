#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#define MAX 2000001

using namespace std;
int N, X, S, E;
int arr[MAX];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[num]++;
	}
	cin >> X;
	for (int i = 0; i <= X; i++) {
		if (arr[i] != 0) {
			answer += arr[X - i];
		}
	}
	cout << answer / 2 << "\n";

	return 0;
}