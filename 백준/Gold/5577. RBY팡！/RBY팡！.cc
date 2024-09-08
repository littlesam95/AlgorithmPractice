#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
vector<int> Ball;
int answer = INF;

int RBY_Pang(int Down, int Up, int Left) {
	int Successive_Down = 1; // 아래로 연속된 공의 개수
	int Successive_Up = 1; // 위로 연속된 공의 개수
	int next_Down = Down; // 아래쪽 인덱스
	int next_Up = Up; // 위쪽 인덱스
	while ((next_Up + 1 < N) && (Ball[next_Up] == Ball[next_Up + 1])) {
		// 범위를 벗어나지 않으면서, 위로 연속된 공의 개수 파악
		next_Up++;
		Successive_Up++;
	};
	while ((next_Down - 1 >= 0) && (Ball[next_Down] == Ball[next_Down - 1])) {
		// 범위를 벗어나지 않으면서, 아래로 연속된 공의 개수 파악
		next_Down--;
		Successive_Down++;
	};
	int Max_Successive;
	if (Ball[Down] == Ball[Up]) { // Down번째 공과 Up번째 공이 같다면 연속된 같은 색깔의 공의 개수를 구한다.
		if (Down == Up) {
			Max_Successive = Successive_Up + Successive_Down - 1;
		}
		else {
			Max_Successive = Successive_Up + Successive_Down;
		}
	}
	else { // 다르다면 아래쪽 연속된 공의 개수 혹은 위쪽 연속된 공의 개수 둘 중 더 큰 값이 최대로 연속된 공의 개수가 된다.
		Max_Successive = max(Successive_Down, Successive_Up);
	}
	if (Max_Successive >= 4) { // 최대로 연속된 공의 개수가 4개 이상이면
		if (Left - Max_Successive < 4) { // 최대로 연속된 공의 개수를 남아 있는 공의 개수에서 빼줬는데 3 이하라면 더 이상 제거할 공이 없다.
			return (Left - Max_Successive);
		}
		// 최대로 연속된 공의 개수를 남아 있는 공의 개수에서 빼줬는데 공이 4개 이상 남아 있다면
		if (next_Down == 0) { // 현재 공의 아래쪽에 더 확인할 공이 없는 경우
			next_Down = next_Up;
		}
		else {
			next_Down--;
		}
		if (next_Up == N - 1) { // 현재 공의 위쪽에 더 확인할 공이 없는 경우
			next_Up = next_Down;
		}
		else {
			next_Up++;
		}
		return RBY_Pang(next_Down, next_Up, Left - Max_Successive); // 공이 4개 이상 남아 있다면 재귀를 사용하여 계속 제거할 공이 있는지 확인
	}
	else { // 아니라면 더 이상 제거할 공이 없다는 뜻이므로, 남아 있는 공의 개수를 return
		return Left;
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		int X;
		cin >> X;
		Ball.push_back(X);
	}
	for (int i = 0; i < N; i++) {
		int CurB = Ball[i]; // i번째 공 따로 저장
		int M = INF;
		for (int j = 1; j <= 3; j++) { // i번째 공의 원래 색깔을 제외한 다른 색으로 바꿔가면서 확인
			if (CurB == j) {
				continue;
			}
			Ball[i] = j;
			M = min(M, RBY_Pang(i, i, N));
		}
		answer = min(answer, M);
		Ball[i] = CurB;
	}
	cout << answer << "\n";

	return 0;
}