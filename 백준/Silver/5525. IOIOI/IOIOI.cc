#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;
	cin >> M;
	char S[1000001];

	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}

	int count = 0;
	int result = 0;
	for (int i = 1; i < M - 1; i++) {
		if ((S[i - 1] == 'I') && (S[i] == 'O') && (S[i + 1] == 'I')) {
			count++;
			if (count == N) {
				count--;
				result++;
			}
			i++;
		}
		else {
			count = 0;
		}
	}

	cout << result;

	return 0;
}