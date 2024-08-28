#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N;
int dist[21][21];
int route[21][21];
vector<int> vec;
int answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			route[i][j] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if ((i == j) || (j == k) || (i == k)) {
					continue;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					route[i][j] = 0;
				}
				else if (dist[i][j] > dist[i][k] + dist[k][j]) {
					answer = -1;
					break;
				}
			}
			if (answer == -1) {
				break;
			}
		}
		if (answer == -1) {
			break;
		}
	}
	if (answer == -1) {
		cout << answer << "\n";
	}
	else {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (route[i][j] == 1) {
					answer += dist[i][j];
				}
			}
		}
		cout << answer << "\n";
	}

	return 0;
}