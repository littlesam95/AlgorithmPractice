#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N, W;
int arr[1010][1010];
int dp[1010][1010] = { 0, };
vector<pair<int, int> > vec;
vector<int> point;
int answer = 0;

void init() {
	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			dp[i][j] = -1;
		}
	}
}

int total(int car1, int car2) {
	if ((car1 == W) || (car2 == W)) {
		return 0;
	}
	if (dp[car1][car2] != -1) {
		return dp[car1][car2];
	}

	int now_car1_y, now_car1_x, now_car2_y, now_car2_x;
	if (car1 > 0) {
		now_car1_y = vec[car1 - 1].first;
		now_car1_x = vec[car1 - 1].second;
	}
	if (car2 > 0) {
		now_car2_y = vec[car2 - 1].first;
		now_car2_x = vec[car2 - 1].second;
	}
	int next_point = max(car1, car2) + 1;
	int next_car_y = vec[next_point - 1].first;
	int next_car_x = vec[next_point - 1].second;
	int dist1, dist2;

	if (car1 == 0) {
		dist1 = abs(1 - next_car_y) + abs(1 - next_car_x);
	}
	else {
		dist1 = abs(now_car1_y - next_car_y) + abs(now_car1_x - next_car_x);
	}

	if (car2 == 0) {
		dist2 = abs(N - next_car_y) + abs(N - next_car_x);
	}
	else {
		dist2 = abs(now_car2_y - next_car_y) + abs(now_car2_x - next_car_x);
	}

	int answer1 = dist1 + total(next_point, car2);
	int answer2 = dist2 + total(car1, next_point);

	dp[car1][car2] = min(answer1, answer2);
	return dp[car1][car2];
}

void dfs(int car1, int car2) {
	if ((car1 == W) || (car2 == W)) {
		return;
	}

	int now_car1_y, now_car1_x, now_car2_y, now_car2_x;
	if (car1 > 0) {
		now_car1_y = vec[car1 - 1].first;
		now_car1_x = vec[car1 - 1].second;
	}
	if (car2 > 0) {
		now_car2_y = vec[car2 - 1].first;
		now_car2_x = vec[car2 - 1].second;
	}
	int next_point = max(car1, car2) + 1;
	int next_car_y = vec[next_point - 1].first;
	int next_car_x = vec[next_point - 1].second;
	int dist1, dist2;

	if (car1 == 0) {
		dist1 = abs(1 - next_car_y) + abs(1 - next_car_x);
	}
	else {
		dist1 = abs(now_car1_y - next_car_y) + abs(now_car1_x - next_car_x);
	}

	if (car2 == 0) {
		dist2 = abs(N - next_car_y) + abs(N - next_car_x);
	}
	else {
		dist2 = abs(now_car2_y - next_car_y) + abs(now_car2_x - next_car_x);
	}

	if (dp[next_point][car2] + dist1 < dp[car1][next_point] + dist2) {
		cout << 1 << "\n";
		dfs(next_point, car2);
	}
	else {
		cout << 2 << "\n";
		dfs(car1, next_point);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	cin >> W;
	for (int i = 0; i < W; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back(make_pair(n1, n2));
	}

	cout << total(0, 0) << "\n";
	dfs(0, 0);

	return 0;
}