#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N, M, Q;
pair<int, int> monkey[501];
int dist[501][501]; // 플로이드-와샬 알고리즘을 사용하여 저장할 최단 경로일 때 비용
int dist2[501][501]; // dist[][]에 멍멍이가 원숭이를 가장 오래 괴롭힐 수 있는 시간을 합한다.
vector<pair<int, int> > query;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist[i][j] = monkey[i].first;
				continue;
			}
			else {
				dist[i][j] = MAX;
				dist2[i][j] = MAX;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) { // 멍멍이가 원숭이를 괴롭히는 시간 입력
		cin >> monkey[i].first;
		monkey[i].second = i; // 정보를 pair<>로 저장하여 first에는 괴롭히는 시간, second에는 도시 번호
	}
	init();
	for (int i = 0; i < M; i++) { // 경로 및 비용 저장
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist2[i][j] = monkey[i].first; // i와 j는 같은 도시이므로 dist2[][]에는 멍멍이가 원숭이를 괴롭히는 시간만 저장
			}
			else {
				dist2[i][j] = dist[i][j] + max(monkey[i].first, monkey[j].first); // i에서 j로 가는 비용 + 멍멍이가 원숭이를 최대로 괴롭힐 수 있는 시간
			}
		}
	}
	sort(monkey + 1, monkey + N + 1); // 멍멍이가 원숭이를 괴롭히는 정보 정렬
	int monkey_idx[501];
	for (int i = 1; i <= N; i++) {
		monkey_idx[monkey[i].second] = i; // 정렬됨에 따라 도시의 번호가 오름차순이 되지 않았으므로 따로 번호를 저장한다.
	}
	for (int k = 1; k <= N; k++) {
		int num = monkey[k].second; // 괴롭히는 시간을 기준으로 오름차순으로 되어있기 때문에 도시 번호는 오름차순이 아니다. 따라서 도시 번호를 따로 저장
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int big = max(monkey[monkey_idx[i]].first, max(monkey[monkey_idx[j]].first, monkey[k].first));
				// 세 도시 중 멍멍이가 원숭이를 가장 오래 괴롭힐 수 있는 도시의 시간을 결정
				if (dist[i][j] > dist[i][num] + dist[num][j]) { // dist[][]에는 최단 경로 저장
					dist[i][j] = dist[i][num] + dist[num][j];
				}
				if (dist2[i][j] > dist[i][num] + dist[num][j] + big) { // dist2[][]에는 멍멍이가 원숭이를 괴롭힐 수 있는 시간을 포함하여 최단 경로 저장
					dist2[i][j] = dist[i][num] + dist[num][j] + big;
				}
			}
		}
	}
	
	// 출발도시와 도착도시를 입력하고 최단 경로일 때 드는 비용(최소 시간) 출력
	for (int i = 0; i < Q; i++) {
		int S, T;
		cin >> S >> T;
		if (dist2[S][T] < MAX) {
			cout << dist2[S][T] << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
	
	return 0;
}