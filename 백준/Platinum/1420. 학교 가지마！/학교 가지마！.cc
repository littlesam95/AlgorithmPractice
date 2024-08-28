#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 20002
#define MAX_MAP 101
#define INF 1e9+7

using namespace std;
int N, M, SourceY, SourceX, SinkY, SinkX;
int Source = -1;
int Sink = -1;
int PREV = 0;
char MAP[MAX_MAP][MAX_MAP];
int WORK[MAX];
map<pair<int, int>, int> CAPACITY, FLOW;
vector<int> Vertex[MAX];
int answer = 0;

// 최대 유량 최소 컷(Min Cut Max Flow) : Source와 Sink가 비연결되는 시점까지 간선을 끊어나간다
void ADD_Edge(int A, int B, int C) {
	Vertex[A].push_back(B);
	Vertex[B].push_back(A);
	CAPACITY[make_pair(A, B)] = C;
	CAPACITY[make_pair(B, A)] = 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	// 도시 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'K') { // 도현이의 위치(K)를 Source로 지정한다.
				Source = PREV + 1;
				SourceY = i;
				SourceX = j;
			}
			if (MAP[i][j] == 'H') { // 학교의 위치(H)를 Sink로 지정한다.
				Sink = PREV;
				SinkY = i;
				SinkX = j;
			}
			PREV += 2;
		}
	}

	if ((N == 1) && (M == 1)) { // 도시가 한 칸밖에 없는 경우
		cout << -1 << "\n";
		return 0;
	}
	if ((abs(SourceY - SinkY) + abs(SourceX - SinkX) == 1) || (Source == -1) || (Sink == -1)) {
		// 도현이가 학교 바로 상하좌우 한 칸 옆에 있어 학교에 가는 것을 막을 수 없거나, 도현이나 학교의 위치 정보가 주어지지 않는 경우
		cout << -1 << "\n";
		return 0;
	}
	for (int i = 0; i < (N * M); i++) { // i+j번째 칸의 들어가는 점 : i+j, 나오는 점 : i+j+1을 용량을 1로 두고 간선으로 연결한다.
		ADD_Edge(2 * i, 2 * i + 1, 1);
	}
	PREV = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 아래, 오른쪽 칸과 현재 칸이 벽이 아니라면 간선으로 잇는다.
			if ((i < N - 1) && (MAP[i][j] != '#') && (MAP[i + 1][j] != '#')) { 
				int Next = PREV + 2 * M;
				ADD_Edge(PREV + 1, Next, 2);
				ADD_Edge(Next + 1, PREV, 2);
			}
			if ((j < M - 1) && (MAP[i][j] != '#') && (MAP[i][j + 1] != '#')) {
				int Next = PREV + 2;
				ADD_Edge(PREV + 1, Next, 2);
				ADD_Edge(Next + 1, PREV, 2);
			}
			PREV += 2;
		}
	}

	while (1) {
		memset(WORK, -1, sizeof WORK);
		queue<int> Q;
		Q.push(Source);

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if ((WORK[Next] == -1) && (CAPACITY[make_pair(Cur, Next)] - FLOW[make_pair(Cur, Next)] > 0)) {
					WORK[Next] = Cur;
					Q.push(Next);
				}
			}
		};

		if (WORK[Sink] == -1) {
			break;
		}
		for (int i = Sink; i != Source; i = WORK[i]) {
			FLOW[make_pair(WORK[i], i)]++;
			FLOW[make_pair(i, WORK[i])]--;
		}
		answer++;
	};
	cout << answer << "\n";

	return 0;
}