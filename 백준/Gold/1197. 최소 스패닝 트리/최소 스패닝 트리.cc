#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10001
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct INFO {
    int A, B, C;
};

int V, E, A, B, C;
vector<INFO> Edges;
int Parent[MAX];
int Answer;

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        Edges.push_back({ A,B,C });
    }
    for (int i = 0; i < V; i++) {
        Parent[i] = i;
    }
}

int find_Parent(int X) {
    if (Parent[X] == X) {
        return X;
    }

    return Parent[X] = find_Parent(Parent[X]);
}

void union_Group(int X, int Y) {
    int ParentX = find_Parent(X);
    int ParentY = find_Parent(Y);

    if (ParentX < ParentY) {
        Parent[ParentY] = ParentX;
    }
    else {
        Parent[ParentX] = ParentY;
    }
}

bool comp(INFO A, INFO B) {
    return (A.C < B.C);
}

void settings() {
    sort(Edges.begin(), Edges.end(), comp);
    for (int i = 0; i < E; i++) {
        int From = Edges[i].A;
        int To = Edges[i].B;
        int Cost = Edges[i].C;
        if (find_Parent(From) != find_Parent(To)) {
            union_Group(From, To);
            Answer += Cost;
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {    
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}