#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

int P, A;
int visit[300001];

void dfs(int num) {
	visit[num]++;
	if (visit[num] == 3) {
		return;
	}
	int sum = 0;
	while (num) {
		sum += (int)pow((num % 10), P);
		num /= 10;
	};
	dfs(sum);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> P;
	
	dfs(A);

	int count = 0;
	for (int i = 0; i < 300001; i++) {
		if (visit[i] == 1) {
			count++;
		}
	}
	cout << count << "\n";

	return 0;
}