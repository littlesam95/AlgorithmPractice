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
    int X, Y;
};

int N, X, Y, minX, minY, First, Left, Right;
POINT Center;
vector<POINT> Point;
vector<POINT> CV;
int Answer;

void init() {
    minX = INF;
    minY = INF;
    Center.X = 0;
    Center.Y = 0;
}

int distance(POINT A, POINT B) {
    return (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
}

LL CCW(POINT A, POINT B, POINT C) {
    LL OP = ((A.X * B.Y) + (B.X * C.Y) + (C.X * A.Y));
    OP -= ((A.Y * B.X) + (B.Y * C.X) + (C.Y * A.X));
    return OP;
}

bool Comp(POINT A, POINT B) {
    LL NowCCW = CCW(Point[0], A, B);
    if (NowCCW > 0) {
        return true;
    }
    else if (NowCCW < 0) {
        return false;
    }
    if (A.X != B.X) {
        return (A.X < B.X);
    }
    return (A.Y < B.Y);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y;
        POINT Tmp;
        Tmp.X = X;
        Tmp.Y = Y;
        Point.push_back(Tmp);
    }
}

void graham_Scan() {
    for (int i = 0; i < Point.size(); i++) {
        if ((minX > Point[i].X) || ((minX == Point[i].X) && (minY > Point[i].Y))) {
            minX = Point[i].X;
            minY = Point[i].Y;
            First = i;
        }
    }
    swap(Point[0], Point[First]);
    sort(Point.begin() + 1, Point.end(), Comp);
    for (int i = 0; i < Point.size(); i++) {
        while ((CV.size() >= 2) && (CCW(Point[i], CV[CV.size() - 2], CV.back()) <= 0)) {
            CV.pop_back();
        };
        CV.push_back(Point[i]);
    }
}

void rotating_Calipers() {
    for (int i = 0; i < CV.size(); i++) {
        if (CV[i].X < CV[Left].X) {
            Left = i;
        }
        else if (CV[i].X > CV[Right].X) {
            Right = i;
        }
    }
    Answer = distance(CV[Left], CV[Right]);
    for (int i = 0; i < CV.size(); i++) {
        POINT Prev, Next;
        Prev.X = CV[(Left + 1) % (int)CV.size()].X - CV[Left].X;
        Prev.Y = CV[(Left + 1) % (int)CV.size()].Y - CV[Left].Y;
        Next.X = CV[Right].X - CV[(Right + 1) % (int)CV.size()].X;
        Next.Y = CV[Right].Y - CV[(Right + 1) % (int)CV.size()].Y;
        if (CCW(Center, Prev, Next) > 0) {
            Left = (Left + 1) % (int)CV.size();
        }
        else {
            Right = (Right + 1) % (int)CV.size();
        }
        Answer = max(Answer, distance(CV[Left], CV[Right]));
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