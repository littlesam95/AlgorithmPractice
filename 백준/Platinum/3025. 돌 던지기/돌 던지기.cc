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
#define MAX_R 30005
#define MAX_C 35
#define LL long long
#define INF 1e9

/*
	직접적으로 돌의 경로를 찾아서 돌을 떨군다면 골드4~5정도의 난이도가 되겠지만
	역시나 플래티넘 문제라 그런 어설픈 방법은 통하지 않는다.
	왜냐하면 높이가 최대 3만까지인데, 돌까지 최대 10만번 던지니,
	일반적인 방법으로 푼다면 시간 초과가 발생한다.
	따라서 다른 방식으로 접근해야 한다.
	구글링을 통해서 돌이 움직인 경로를 적어주는 방식으로 접근한다면,
	다음 돌을 던질 때 돌이 어디로 갈 지 먼저 파악할 수 있으니,
	시간을 많이 줄일 수 있다.
*/

using namespace std;
int R, C, N;
int MAP[MAX_R][MAX_C];
set<int> Wall[MAX_C]; // C열에 있는 장애물의 행
/*
	각 열마다 존재하는 벽 또는 돌의 위치를 나타내기 위하여 set을 사용하였다.
	set은 원소들을 자동으로 오름차순 정렬시켜주는 특징을 가지고 있다.
*/
stack<pair<int, int> > Check_Pos[MAX_C]; // 1행 C열에서 떨어뜨리는 돌의 체크포인트 좌표
/*
	돌들의 경로를 저장해주기 위한 체크포인트이다.
	체크포인트에 해당하는 칸의 바로 윗 칸에 돌이 떨어진다.
*/

void Stone_Falling(int Row, int Col, int First) { // Row, Col은 돌이 떨어지는 곳, First는 돌을 던졌던 처음 열
	int H = *(Wall[Col].upper_bound(Row)); // Col열에서, 돌이 떨어지면서 다른 곳과 부딪힐 높이 찾기

	if (MAP[H][Col] == 1) { // 떨어지는 돌이 H행 Col열에서 돌을 만났을 때
		// 왼쪽 칸과 왼쪽 아래 칸이 빈 칸이라면 왼쪽 아래 칸으로 떨어진다. Col이 1 미만이 되면 안 되므로 예외처리를 해준다.
		if ((Col - 1 >= 1) && (MAP[H][Col - 1] == 0) && (MAP[H - 1][Col - 1] == 0)) {
			// MAP[H - 1][Col - 1]가 바로 왼쪽 칸, MAP[H][Col - 1]이 바로 왼쪽 아래 칸을 의미한다.
			Check_Pos[First].push(make_pair(H - 1, Col)); // 현재 돌이 왼쪽 아래 칸으로 떨어졌으므로, 체크포인트로 지정
			Stone_Falling(H - 1, Col - 1, First); // 왼쪽 아래로 떨어진 후 다시 떨어질 체크포인트 찾기
		}
		// 오른쪽 칸과 오른쪽 아래 칸이 빈 칸이라면 오른쪽 아래 칸으로 떨어진다. Col이 C 초과가 되면 안 되므로 예외처리를 해준다.
		else if ((Col + 1 <= C) && (MAP[H][Col + 1] == 0) && (MAP[H - 1][Col + 1] == 0)) {
			Check_Pos[First].push(make_pair(H - 1, Col)); // 현재 돌이 오른쪽 아래 칸으로 떨어졌으므로, 체크포인트로 지정
			Stone_Falling(H - 1, Col + 1, First); // 오른쪽 아래로 떨어진 후 다시 떨어질 체크포인트 찾기
		}
		// 떨어질 곳이 없다면 돌은 멈추고 다시는 움직이지 않는다.
		else {
			MAP[H - 1][Col] = 1;
			Wall[Col].erase(H);
			Wall[Col].insert(H - 1);
		}

	}
	else { // 떨어지는 곳이 벽이라면
		MAP[H - 1][Col] = 1; // 벽 위로 떨어진다.
		Wall[Col].erase(H);
		Wall[Col].insert(H - 1);
	}
}

void Print() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (MAP[i][j] == 0) {
				cout << ".";
			}
			else if (MAP[i][j] == 1) {
				cout << "O";
			}
			else if (MAP[i][j] == -1) {
				cout << "X";
			}
		}
		cout << "\n";
	}
}

int main() {
	FIRST
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= C; j++) {
			if (S[j - 1] == '.') {
				MAP[i][j] = 0;
			}
			else if (S[j - 1] == 'X') {
				MAP[i][j] = -1;
				Wall[j].insert(i); // j열 i행에 벽이 생겼으므로, Wall[j]에 i를 insert한다.
			}
		}
	}
	for (int i = 1; i <= C; i++) {
		// 행은 1부터 R까지 존재하므로, R+1행에 벽이 있다고 생각해도 상관없다.
		Wall[i].insert(R + 1);
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Col, Y, X;
		cin >> Col;
		/*
			돌을 떨어뜨릴 때, 이전 돌들이 이동한 경로를 찾아야 한다.
		*/
		while (!Check_Pos[Col].empty()) { // Col열에서의 현재 체크포인트
			Y = Check_Pos[Col].top().first;
			X = Check_Pos[Col].top().second;
			if (MAP[Y][X] != 0) { // 현재 체크포인트가 빈 칸이 아닐 때, 즉 현재 체크포인트에 돌이 존재할 때
				Check_Pos[Col].pop(); // 현재 칸에는 이제 돌이 존재하므로, 체크포인트로 사용될 수 없음
			}
			else { // 현재 체크포인트에 돌을 떨어뜨릴 것이다. 따라서 체크포인트를 더 탐색할 필요가 없으므로, 반복문을 종료한다.
				break;
			}
		};
		if (Check_Pos[Col].empty()) { // Col열에 체크포인트가 더 이상 없는 경우
			Stone_Falling(1, Col, Col); // 이 때는 돌을 떨구기 위해 사용할 이전 돌들의 이동 경로가 없으므로, 처음 1행에서 돌을 떨군다.
		}
		else { // Col열에 체크포인트가 존재하는 경우
			Stone_Falling(Y, X, Col); // 이 때는 이미 돌을 1행에서 떨구어, 돌이 (Y, X)까지 왔을 때이므로, 시작점을 (Y, X)로 한다.
		}
	}
	Print();

	return 0;
}