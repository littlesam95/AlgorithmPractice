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

	int N, M;
	cin >> N >> M;
	int i1, i2;
	vector<vector<int> > bad(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++) {
		cin >> i1 >> i2;
		bad[i1][i2] = 1;
		bad[i2][i1] = 1;
	}
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				if ((bad[i][j] != 1) && (bad[i][k] != 1) && (bad[j][k] != 1)) {
					count++;
				}
			}
		}
	}

	cout << count;

	return 0;
}