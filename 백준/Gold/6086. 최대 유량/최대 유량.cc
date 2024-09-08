#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 60
#define INF 2e9

using namespace std;
int N;
int Source = 0; // 우물
int Sink = 'Z' - 'A'; // 외양간
int CAPACITY[MAX][MAX]; // i에서 j까지 흐를 때 필요한 간선 용량
int FLOW[MAX][MAX]; // i에서 j까지 흐르는 유량
vector<int> Vertex[MAX]; // 역방향 간선
int Total_Flow = 0;

// 에드먼드-카프 알고리즘(Edmonds-Karp Algorithm)
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) { // 파이프의 정보를 입력
		char CFrom, CTo;
		int Value;
		cin >> CFrom >> CTo >> Value;
		// 입력받은 문자를 0~51 사이의 값으로 변환한다.
		int From, To;
		if ((CFrom >= 'A') && (CFrom <= 'Z')) {
			From = CFrom - 'A';
		}
		else {
			From = CFrom - 'a' + 26;
		}
		if ((CTo >= 'A') && (CTo <= 'Z')) {
			To = CTo - 'A';
		}
		else {
			To = CTo - 'a' + 26;
		}
		// From에서 To로 갈 때 필요한 용량 더하기
		CAPACITY[From][To] += Value;
		CAPACITY[To][From] += Value;
		// 역방향 간선 추가
		Vertex[From].push_back(To);
		Vertex[To].push_back(From);
	};

	while (1) {
		int PREV[MAX];
		memset(PREV, -1, sizeof PREV);
		queue<int> q;
		q.push(Source);

		while (!q.empty()) {
			int nowS = q.front();
			q.pop();

			for (int i = 0; i < Vertex[nowS].size(); i++) {
				int nextS = Vertex[nowS][i];
				if (PREV[nextS] == -1) { // 방문하지 않았던 nextS일 때,
					if (CAPACITY[nowS][nextS] > FLOW[nowS][nextS]) { // nowS에서 nextS로 흐를 수 있는 유량이 있다면
						q.push(nextS);
						PREV[nextS] = nowS; // nextS의 경로 추적을 위해 저장한다.
						if (nextS == Sink) { // nextS가 Sink면 break
							break;
						}
					}
				}
			}
		};
		if (PREV[Sink] == -1) { // Source에서 Sink로의 간선이 없다면 break
			break;
		}
		int flow = INF; // 지금까지 구한 경로 상에서 가장 유량이 낮은 곳을 구하기 위해 flow를 INF로 초기화시켰다.
		for (int i = Sink; i != Source; i = PREV[i]) {
			flow = min(flow, CAPACITY[PREV[i]][i] - FLOW[PREV[i]][i]);
		}
		// 유량이 가장 낮은 간선에 flow를 보내고 역방향 간선에서 flow만큼 빼준다.
		for (int i = Sink; i != Source; i = PREV[i]) {
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
		Total_Flow += flow;
	};
	cout << Total_Flow << "\n";

	return 0;
}