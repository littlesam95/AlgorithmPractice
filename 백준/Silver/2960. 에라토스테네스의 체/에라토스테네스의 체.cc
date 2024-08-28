#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define MAX 250001

using namespace std;
int N, K;
int IDX = 0;
bool Flag = false;
int DP[MAX];
int answer;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		DP[i] = i;
	}
	while (1) {
		for (int i = 2; i <= N; i++) {
			if (DP[i] != 0) {
				DP[i] = 0;
				IDX++;
				if (K == IDX) {
					answer = i;
					Flag = true;
					break;
				}
				for (int j = i * i; j <= N; j += i) {
					if (DP[j] != 0) {
						DP[j] = 0;
						IDX++;
						if (K == IDX) {
							answer = j;
							Flag = true;
							break;
						}
					}
				}
			}
			if (Flag) {
				break;
			}
		}
		if (Flag) {
			break;
		}
	};
	cout << answer << "\n";

	return 0;
}