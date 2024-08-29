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

int N, X, Y, MinX, MinY, First;
int Case = 1;
vector<POINT> Point, CV;
double Answer;

void init() {
    MinX = INF;
    MinY = INF;
    First = 0;
    Point.clear();
    CV.clear();
    Answer = INF;
}

double distance(POINT A, POINT B) {
    return sqrt(((A.X - B.X) * (A.X - B.X)) + ((A.Y - B.Y) * (A.Y - B.Y)));
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

void calculate() {
    for (int i = 0; i < CV.size(); i++) {
        POINT Prev = CV[i];
        POINT Next = CV[(i + 1) % (int)CV.size()];
        double Distance = distance(Prev, Next);
        double Big = 0;
        for (int j = 0; j < CV.size(); j++) {
            if (((CV[j].X == Prev.X) && (CV[j].Y == Prev.Y)) || ((CV[j].X == Next.X) && (CV[j].Y == Next.Y))) {
                continue;
            }
            LL NowCCW = abs(CCW(Prev, Next, CV[j]));
            double NowD = (double)NowCCW / Distance;
            Big = max(Big, NowD);
        }
        Answer = min(Answer, Big);
    }
    Answer *= 100;
    if (Answer - (LL)Answer > (1e-12)) {
        Answer += 1;
        Answer = (LL)Answer;
    }
    Answer /= 100;
}

void settings() {
    graham_Scan();
    calculate();
}

void find_Answer() {
    cout << "Case " << Case++ << ": ";
    cout << fixed;
    cout.precision(2);
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> N;
        if (N == 0) {
            break;
        }
        init();
        for (int i = 0; i < N; i++) {
            cin >> X >> Y;
            POINT Tmp;
            Tmp.X = X;
            Tmp.Y = Y;
            Point.push_back(Tmp);
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