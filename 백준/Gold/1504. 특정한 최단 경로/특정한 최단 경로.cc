#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 801
#define INF 2e9
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int N, E, V1, V2;
vector<pair<LL, int> > Edge[MAX];
LL Dist[MAX];
LL one2A, one2B, a2B, a2N, b2N, Answer1, Answer2;

void input() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int A, B;
        LL C;
        cin >> A >> B >> C;
        Edge[A].push_back(make_pair(B, C));
        Edge[B].push_back(make_pair(A, C));
    }
    cin >> V1 >> V2;
}

void init() {
    for (int i = 0; i <= N; i++) {
        Dist[i] = INF;
    }
}

void dijkstra(int A) {
    priority_queue<pair<LL, int> > PQ;
    Dist[A] = 0;
    PQ.push(make_pair(0, A));

    while (!PQ.empty()) {
        LL CurD = -PQ.top().first;
        int CurX = PQ.top().second;
        PQ.pop();

        if (Dist[CurX] < CurD) {
            continue;
        }

        for (int i = 0; i < Edge[CurX].size(); i++) {
            LL NextD = Edge[CurX][i].second;
            int NextX = Edge[CurX][i].first;
            if (Dist[NextX] > CurD + NextD) {
                Dist[NextX] = CurD + NextD;
                PQ.push(make_pair(-Dist[NextX], NextX));
            }
        }
    };
}

void settings() {
    init();
    dijkstra(1);
    one2A = Dist[V1]; // 1
    one2B = Dist[V2]; // 2
    init();
    dijkstra(V1);
    a2B = Dist[V2]; // 3
    a2N = Dist[N]; // 4
    init();
    dijkstra(V2);
    b2N = Dist[N]; // 5
    // 1 + 3 + 5와 2 + 3 + 4를 비교해서 최솟값을 구한다. 둘 다 INF이면 -1을 출력.
    Answer1 = one2A + a2B + b2N;
    if ((one2A == INF) || (a2B == INF) || (b2N == INF)) {
        Answer1 = -1;
    }
    Answer2 = one2B + a2B + a2N;
    if ((one2B == INF) || (a2B == INF) || (a2N == INF)) {
        Answer2 = -1;
    }
}

void find_Answer() {
    if ((Answer1 == -1) && (Answer2 != -1)) {
        cout << Answer2 << "\n";
    }
    else if ((Answer1 != -1) && (Answer2 == -1)) {
        cout << Answer1 << "\n";
    }
    else if ((Answer1 != -1) && (Answer2 != -1)) {
        cout << min(Answer1, Answer2) << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}