#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 16

using namespace std;
int L, C;
char arr[MAX];
vector<long long> vec;
vector<string> answer;

bool is_even(char X) {
	if ((X == 'a') || (X == 'e') || (X == 'i') || (X == 'o') || (X == 'u')) {
		return true;
	}
	else return false;
}

void dfs(int X, string password, int even, int odd) {
	if ((password.size() == L) && (even >= 1) && (odd >= 2)) {
		answer.push_back(password);
		return;
	}
	for (int i = X + 1; i < C; i++) {
		dfs(i, password + arr[i], (is_even(arr[i])) ? even + 1 : even, (is_even(arr[i])) ? odd : odd + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + C);
	dfs(-1, "", 0, 0);
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}