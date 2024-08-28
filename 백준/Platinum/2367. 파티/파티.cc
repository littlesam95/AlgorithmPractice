#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 405
#define INF 2e9

using namespace std;
int N, K, D;
int Source = 0;
int Sink = 1;
int PREV[MAX];
int FOOD[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
vector<int> Vertex[MAX];
int Total_Flow = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> D;
	for (int i = N + 2; i < N + 2 + D; i++) { // 음식의 종류마다 가져올 수 있는 양의 제한, D개의 음식에게는 N+2번부터 N+D+1번까지의 번호를 부여한다.
		cin >> FOOD[i];
	}
	for (int i = 2; i <= N + 1; i++) { // N명의 사람에게는 2번부터 N+1번까지의 번호를 부여한다.
		// 각 사람이 요리할 줄 아는 음식의 종류 개수
		int Z;
		cin >> Z;
		// i번째 사람과 Source를 간선으로 연결, Capacity는 K
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		CAPACITY[0][i] = K;
		// Z개의 음식을 각각 i번 사람과 간선으로 연결, Capacity는 1
		while (Z--) {
			int A;
			cin >> A;
			Vertex[i].push_back(N + 1 + A);
			Vertex[N + 1 + A].push_back(i);
			CAPACITY[i][N + 1 + A] = 1;
		};
	}
	for (int i = N + 2; i < N + 2 + D; i++) { // i번째 음식과 Sink를 간선으로 연결, Capacity는 음식의 양 제한 수치
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = FOOD[i];
	}

	while (1) {
		memset(PREV, -1, sizeof PREV);
		queue<int> Q;
		Q.push(Source);

		while (!Q.empty() && (PREV[Sink] == -1)) {
			int Cur = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if (PREV[Next] != -1) {
					continue;
				}
				if (CAPACITY[Cur][Next] > FLOW[Cur][Next]) {
					Q.push(Next);
					PREV[Next] = Cur;
					if (Next == Sink) {
						break;
					}
				}
			}
		};
		if (PREV[Sink] == -1) {
			break;
		}
		int flow = INF;
		for (int i = Sink; i != Source; i = PREV[i]) {
			flow = min(flow, CAPACITY[PREV[i]][i] - FLOW[PREV[i]][i]);
		}
		for (int i = Sink; i != Source; i = PREV[i]) {
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
		Total_Flow += flow;
	};

	cout << Total_Flow << "\n";

	return 0;
}