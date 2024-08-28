#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define INF 2e9
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct POINT {
    LL X, Y;
};

int N, M, First;
LL X, Y, MinX, MinY;
vector<POINT> A, B, Point, CV;

void init() {
    MinX = INF;
    MinY = INF;
}

LL distance(POINT A, POINT B) {
    return (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
}

LL CCW(POINT A, POINT B, POINT C) {
    LL OP = ((A.X * B.Y) + (B.X * C.Y) + (C.X * A.Y));
    OP -= ((A.Y * B.X) + (B.Y * C.X) + (C.Y * A.X));
    return OP;
}

bool Comp(POINT A, POINT B) {
    LL NowCCW = CCW(Point[0], A, B);
    if (NowCCW != 0) {
        return (NowCCW > 0);
    }
    if (A.X != B.X) {
        return (A.X < B.X);
    }
    return (A.Y < B.Y);
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        POINT Tmp;
        Tmp.X = X;
        Tmp.Y = Y;
        A.push_back(Tmp);
    }
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        POINT Tmp;
        Tmp.X = X;
        Tmp.Y = Y;
        B.push_back(Tmp);
    }
}

void minkowski_Sum() {
    for (int i = 0; i < N; i++) {
        LL X1 = A[i].X;
        LL Y1 = A[i].Y;
        for (int j = 0; j < M; j++) {
            LL X2 = B[j].X;
            LL Y2 = B[j].Y;
            POINT Tmp;
            Tmp.X = X1 + X2;
            Tmp.Y = Y1 + Y2;
            Point.push_back(Tmp);
        }
    }
}

void graham_Scan() {
    for (int i = 0; i < Point.size(); i++) {
        if ((MinX > Point[i].X) || ((MinX == Point[i].X) && (MinY > Point[i].Y))) {
            MinX = Point[i].X;
            MinY = Point[i].Y;
            First = i;
        }
    }
    swap(Point[0], Point[First]);
    sort(Point.begin() + 1, Point.end(), Comp);
    for (int i = 0; i < Point.size(); i++) {
        while ((CV.size() >= 2) && (CCW(CV[CV.size() - 2], CV[CV.size() - 1], Point[i]) <= 0)) {
            CV.pop_back();
        };
        CV.push_back(Point[i]);
    }
}

void settings() {
    minkowski_Sum();
    graham_Scan();
}

void find_Answer() {
    cout << CV.size() << "\n";
    for (int i = 0; i < CV.size(); i++) {
        cout << CV[i].X << " " << CV[i].Y << "\n";
    }
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}