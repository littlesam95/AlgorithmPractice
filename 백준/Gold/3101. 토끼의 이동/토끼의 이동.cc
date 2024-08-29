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
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
LL N, K;
LL Diagonal = 1; // (1, 1)이 속해 있는 대각선은 무조건 1번째 대각선
string S;
pair<LL, LL> Rabbit = make_pair(1, 1); // 토끼의 처음 위치는 (1, 1)
LL answer = 1; // 처음에 (1, 1), 즉 1을 방문했으므로 초기값은 1이며, 32비트 정수를 넘을 수 있다고 하였으므로 long long형으로 지정한다.

LL Find_Number(LL Y, LL X) {
	if (Diagonal % 2 == 0) {
		// 짝수번째 대각선인 경우
		if (Diagonal > N) {
			// 대각선 번호가 N을 넘어간 경우 값에서 (대각선 - N) * (대각선 - N)을 빼준다.
			return (((Diagonal * (Diagonal - 1)) / 2) + Y - ((Diagonal - N) * (Diagonal - N)));
		}
		return (((Diagonal * (Diagonal - 1)) / 2) + Y); // (대각선 * (대각선 - 1)) / 2 + X좌표를 더해준 값이 (X, Y)의 값이 된다.
	}
	else if (Diagonal % 2 == 1) {
		// 홀수번째 대각선인 경우
		if (Diagonal > N) {
			return (((Diagonal * (Diagonal + 1)) / 2) - Y + 1 - ((Diagonal - N) * (Diagonal - N)));
		}
		return (((Diagonal * (Diagonal + 1)) / 2) - (Y - 1)); // (대각선 * (대각선 + 1)) / 2 - (X - 1)좌표를 더해준 값이 (X, Y)의 값이 된다.
	}
}

int main() {
	FIRST
	cin >> N >> K;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		LL CurY = Rabbit.first;
		LL CurX = Rabbit.second;
		LL nextY, nextX;
		if (S[i] == 'U') {
			// 위로 한 칸 이동하면 이전 대각선으로 이동한다.
			Diagonal--;
			nextY = CurY - 1;
			nextX = CurX;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'D') {
			// 아래로 한 칸 이동하면 다음 대각선으로 이동한다.
			Diagonal++;
			nextY = CurY + 1;
			nextX = CurX;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'L') {
			// 왼쪽으로 한 칸 이동하면 이전 대각선으로 이동한다.
			Diagonal--;
			nextY = CurY;
			nextX = CurX - 1;
			answer += Find_Number(nextY, nextX);
		}
		else if (S[i] == 'R') {
			// 오른쪽으로 한 칸 이동하면 다음 대각선으로 이동한다.
			Diagonal++;
			nextY = CurY;
			nextX = CurX + 1;
			answer += Find_Number(nextY, nextX);
		}
		Rabbit = make_pair(nextY, nextX);
	}
	cout << answer << "\n";

	return 0;
}