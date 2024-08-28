#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 100001
#define LL long long
#define INF 1e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct INFO {
    int A, B, C;
};

int N, M, A, B, C, Max;
vector<INFO> Edge;
int Parent[MAX];
int Answer;

void init() {
    for (int i = 0; i < MAX; i++) {
        Parent[i] = i;
    }
}

void input() {
    cin >> N >> M;
    while (M--) {
        cin >> A >> B >> C;
        Edge.push_back({ A,B,C });
    };
}

int find_Parent(int X) {
    if (Parent[X] == X) {
        return X;
    }
    return Parent[X] = find_Parent(Parent[X]);
}

void union_Group(int X, int Y) {
    int PX = find_Parent(X);
    int PY = find_Parent(Y);
    if (PX <= PY) {
        Parent[PY] = PX;
    }
    else {
        Parent[PX] = PY;
    }
}

bool Comp(INFO X, INFO Y) {
    return (X.C < Y.C);
}

void settings() {
    sort(Edge.begin(), Edge.end(), Comp);
    for (int i = 0; i < Edge.size(); i++) {
        if (find_Parent(Edge[i].A) != find_Parent(Edge[i].B)) {
            union_Group(Edge[i].A, Edge[i].B);
            Answer += Edge[i].C;
            Max = max(Max, Edge[i].C);
        }
    }
}

void find_Answer() {
    cout << Answer - Max << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}