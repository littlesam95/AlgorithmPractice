#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int N, P;
int arr[20][20];
int dp[20][1 << 20] = { 0, };
string str;
int state = 1 << 20;

void init() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < (1 << 20); j++) {
			dp[i][j] = -1;
		}
	}
}

int count_bits(int n) { // 비트 수를 세는 함수
	int count = 0;
	while (n) {
		count += (n & 1); // 맨 뒤 비트가 1인 경우 count를 증가시킨다.
		n >>= 1; // 비트를 오른쪽으로 한 칸 이동시킨다.
	};

	return count;
}

int dfs(int idx, int now_state) {
	if (count_bits(now_state) - 1 >= P) { // now_state 즉 발전소들의 현재 상태를 파악한다.
		// 비트 수가 P + 1개 이상이라면 고장나지 않은 발전소가 P개 이상이라는 것이므로, 더 이상 발전소를 건드리지 않아도 된다.
		return 0;
	}

	if (dp[idx][now_state] != -1) {
		return dp[idx][now_state];
	}

	dp[idx][now_state] = INT_MAX;
	for (int i = 0; i < N; i++) {
		if (!(now_state & (1 << i))) { // i번째 발전소가 고장났다면
			int next_state = now_state | (1 << i); // i번째 발전소를 고친다.
			for (int j = 0; j < N; j++) {
				if ((next_state & (1 << j))) { // i번째 발전소를 고쳤을 때의 상태를 파악하여 j번째 발전소가 고장나지 않았다면
					dp[idx][now_state] = min(dp[idx][now_state], arr[idx][i] + dfs(j, next_state)); // idx번째, 즉 83번째 줄에서 i번째 발전소를 시작점으로 하는 발전소를 고쳤을 때 드는 총 비용값을 최신화한다.
					// 여기서 비교해야 할 것은 i번째 발전소를 고쳤을 때의 상태, 즉 next_state에서 다시 j번째 발전소를 시작점으로 해서 발전소를 고쳐야 하는지를 파악하기 위한 재귀함수를 실행한 return값(비용) + idx번째 발전소를 이용하여 i번째 발전소를 고칠 때 드는 비용을 더한 값과 비교하여 더 작은 값으로 최신화한다.
				}
			}
		}
	}

	return dp[idx][now_state]; // idx번째 발전소를 시작점으로 하는, 발전소를 고치는 데 드는 최소의 비용을 return한다.
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) { // 발전소 비용 입력
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> str;
	for (int i = 0; i < str.size(); i++) { // 발전소 상태 입력, Y인 경우 i + 1번째 비트를 1로 변경, N인 경우 0.
		if (str[i] == 'Y') {
			state |= (1 << i);
		}
	}
	cin >> P;
	if (!P) {
		cout << 0 << "\n"; // P가 0, 즉 고장나지 않은 발전소가 최소 0개 이상이라고 하면 발전소를 건드릴 필요가 없기 때문에 비용이 들지 않는다.
	}
	else { // P가 1 이상인 경우
		init();
		int result = INT_MAX;
		for (int i = 0; i < N; i++) {
			if (str[i] == 'Y') {
				result = min(result, dfs(i, state)); // 켜져 있는 발전소를 찾아 고장난 발전소를 고치고 상태를 최신화한다.
				// 상태를 최신화할 때는 재귀함수를 이용한다.
			}
		}

		if (result == INT_MAX) { // result가 정수형의 최댓값인 경우 발전소를 고치는 것이 불가능하다는 뜻이다. 따라서 -1을 출력한다.
			cout << -1 << "\n";
		}
		else {
			cout << result << "\n";
		}
	}

	return 0;
}