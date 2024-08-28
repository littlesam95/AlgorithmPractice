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

LL N, PX, PY, X, Y, MinX, MinY, First;
vector<POINT> Point;
vector<POINT> CV;
bool Flag = true;
int Answer;

void init() {
    MinX = INF;
    MinY = INF;
    CV.clear();
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
    cin >> N >> PX >> PY;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        POINT Tmp;
        Tmp.X = X;
        Tmp.Y = Y;
        Point.push_back(Tmp);
    }
}

bool isInner() {
    int point_count = 0;
    for (int i = 0; i < CV.size(); i++) {
        int j = (i + 1) % (int)CV.size();

        bool Flag = ((PY > CV[i].Y) != (PY > CV[j].Y));
        if (Flag) {
            int S[3] = { 0, };
            S[0] = CV[j].X - CV[i].X;
            S[1] = CV[j].Y - CV[i].Y;
            S[2] = PY - CV[i].Y;

            float posX = (S[0] * S[2]) / S[1] + CV[i].X;
            if (PX < posX) {
                point_count++;
            }
        }
    }
    return ((point_count % 2) != 0);
}

void graham_Scan() {
    if (Point.size() <= 2) {
        Flag = false;
        return;
    }
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
        while ((CV.size() >= 2) && (CCW(Point[i], CV[CV.size() - 2], CV[CV.size() - 1]) <= 0)) {
            CV.pop_back();
        };
        CV.push_back(Point[i]);
    }
    if (CV.size() <= 2) {
        Flag = false;
        return;
    }
    for (int i = 0; i < CV.size(); i++) {
        for (int j = 0; j < Point.size(); j++) {
            if ((Point[j].X == CV[i].X) && (Point[j].Y == CV[i].Y)) {
                Point.erase(Point.begin() + j);
                break;
            }
        }
    }
}

void settings() {
    while (1) {
        init();
        graham_Scan();
        if ((!Flag) || !isInner()) {
            break;
        }
        Answer++;
    };
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