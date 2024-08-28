#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define MAX 201
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct RECTANGLE {
    int X1, Y1, X2, Y2;
};

int T, N, X1, Y1, X2, Y2;
vector<RECTANGLE> Rectangles;
int Parent[MAX];
set<int> Answer;

void init() {
    Rectangles.clear();
    for (int i = 0; i < MAX; i++) {
        Parent[i] = i;
    }
    Answer.clear();
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

bool intersect_Rectangles(RECTANGLE A, RECTANGLE B) {
    if ((A.X1 <= B.X2) && (A.X2 >= B.X1) && (A.Y2 >= B.Y1) && (A.Y1 <= B.Y2)) {
        return true;
    }

    return false;
}

void settings() {
    for (int i = 0; i < N; i++) {
        for (int j = (i + 1); j < N; j++) {
            if ((find_Parent(i) != find_Parent(j)) && (intersect_Rectangles(Rectangles[i], Rectangles[j]))) {
                union_Group(i, j);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        Answer.insert(find_Parent(i));
    }
}

void find_Answer() {
    cout << (int)Answer.size() << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        init();
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> X1 >> Y1 >> X2 >> Y2;
            Rectangles.push_back({ X1,Y1,X2,Y2 });
        }
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}