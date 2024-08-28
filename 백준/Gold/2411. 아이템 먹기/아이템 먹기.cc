#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101

using namespace std;
int N, M, A, B;
int arr[MAX][MAX];
int dp[MAX][MAX];
vector<pair<int, int> > vec;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.first == B.first) {
		return (A.second < B.second);
	}
	return (A.first < B.first);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> A >> B;
	for (int i = 0; i < A; i++) {
		int Y, X;
		cin >> Y >> X;
		arr[Y][X] = 1;
		vec.push_back(make_pair(Y, X));
	}
	vec.push_back(make_pair(N, M));
	for (int i = 0; i < B; i++) {
		int Y, X;
		cin >> Y >> X;
		arr[Y][X] = -1;
	}
	dp[1][0] = 1;
	sort(vec.begin(), vec.end(), comp);
	int startY = 1;
	int startX = 1;
	for (int i = 0; i < vec.size(); i++) {
		int endY = vec[i].first;
		int endX = vec[i].second;
		for (int i = startY; i <= endY; i++) {
			for (int j = startX; j <= endX; j++) {
				if (arr[i][j] == -1) {
					dp[i][j] = 0;
				}
				else if ((arr[i - 1][j] != -1) && (arr[i][j - 1] != -1)) {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
				else if (arr[i - 1][j] != -1) {
					dp[i][j] = dp[i - 1][j];
				}
				else if (arr[i][j - 1] != -1) {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		startY = endY;
		startX = endX;
	}
	cout << dp[N][M] << "\n";

	return 0;
}