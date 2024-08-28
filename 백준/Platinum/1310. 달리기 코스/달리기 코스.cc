#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define INF 2e9
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct Point {
    LL X, Y;
};

LL N, X, Y, minX, minY, First, Left, Right;
Point Center;
vector<Point> Vec;
vector<Point> Convex_Hull;
LL Answer;

void init() {
    minX = INF;
    minY = INF;
    Center.X = 0;
    Center.Y = 0;
}

LL distance(Point A, Point B) {
    return (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
}

LL CCW(const Point &A, const Point &B, const Point &C) {
    LL OP = A.X * B.Y + B.X * C.Y + C.X * A.Y;
    OP -= (A.Y * B.X + B.Y * C.X + C.Y * A.X);
    return OP;
}

bool Comp(const Point &A, const Point &B) {
    LL ccwValue = CCW(Vec[0], A, B);
    if (ccwValue > 0) {
        return true;
    }
    else if (ccwValue < 0) {
        return false;
    }
    if (A.X != B.X) {
        return (A.X < B.X);
    }
    return (A.Y < B.Y);
}

void input() {
    cin >> N;
    for (LL i = 0; i < N; i++) {
        cin >> X >> Y;
        Point P;
        P.X = X;
        P.Y = Y;
        Vec.push_back(P);
    }
}

void graham_Scan() {
    for (LL i = 0; i < N; i++) {
        if ((minX > Vec[i].X) || ((minX == Vec[i].X) && (minY > Vec[i].Y))) {
            minX = Vec[i].X;
            minY = Vec[i].Y;
            First = i;
        }
    }
    swap(Vec[0], Vec[First]);
    sort(Vec.begin() + 1, Vec.end(), Comp);
    for (int i = 0; i < Vec.size(); i++) {
        while ((Convex_Hull.size() >= 2) && (CCW(Vec[i], Convex_Hull[Convex_Hull.size() - 2], Convex_Hull.back()) <= 0)) {
            Convex_Hull.pop_back();
        };
        Convex_Hull.push_back(Vec[i]);
    }
}

void rotating_Calipers() {
    for (int i = 0; i < Convex_Hull.size(); i++) {
        if (Convex_Hull[i].X < Convex_Hull[Left].X) {
            Left = i;
        }
        else if (Convex_Hull[i].X > Convex_Hull[Right].X) {
            Right = i;
        }
    }
    Answer = distance(Convex_Hull[Left], Convex_Hull[Right]);
    for (int i = 0; i < Convex_Hull.size(); i++) {
        Point Prev;
        Prev.X = Convex_Hull[(Left + 1) % ((int)Convex_Hull.size())].X - Convex_Hull[Left].X;
        Prev.Y = Convex_Hull[(Left + 1) % ((int)Convex_Hull.size())].Y - Convex_Hull[Left].Y;
        Point Next;
        Next.X = Convex_Hull[Right].X - Convex_Hull[(Right + 1) % ((int)Convex_Hull.size())].X;
        Next.Y = Convex_Hull[Right].Y - Convex_Hull[(Right + 1) % ((int)Convex_Hull.size())].Y;
        if (CCW(Center, Prev, Next) > 0) {
            Left = (Left + 1) % ((int)Convex_Hull.size());
        }
        else {
            Right = (Right + 1) % ((int)Convex_Hull.size());
        }
        LL NowD = distance(Convex_Hull[Left], Convex_Hull[Right]);
        Answer = max(Answer, NowD);
    }
}

void settings() {
    graham_Scan();
    rotating_Calipers();
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}