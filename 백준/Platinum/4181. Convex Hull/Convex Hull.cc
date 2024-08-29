#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 2e9
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct Point {
    LL X, Y;
};

LL N, X, Y;
char C;
int minX = INF;
int minY = INF;
int minI = 0;
vector<Point> Vec;
vector<Point> R;
vector<Point> Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X >> Y >> C;
        if (C == 'Y') {
            Vec.push_back({X, Y});
        }
    }
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

void settings() {
    for (int i = 0; i < Vec.size(); i++) {
        if ((minX > Vec[i].X) || ((minX == Vec[i].X) && (minY > Vec[i].Y))) {
            minX = Vec[i].X;
            minY = Vec[i].Y;
            minI = i;
        }
    }
    Vec[minI].X = Vec[0].X;
    Vec[minI].Y = Vec[0].Y;
    Vec[0].X = minX;
    Vec[0].Y = minY;
    sort(Vec.begin() + 1, Vec.end(), Comp);
    for (int i = 0; i < Vec.size(); i++) {
        while ((Answer.size() >= 2) && (CCW(Answer[Answer.size() - 2], Answer.back(), Vec[i]) < 0)) {
            R.push_back(Answer.back());
            Answer.pop_back();
        };
        Answer.push_back(Vec[i]);
    }
    for (int i = R.size() - 1; i >= 0; i--) {
        Answer.push_back(R[i]);
    }
}

void find_Answer() {
    cout << Answer.size() << "\n";
    for (int i = 0; i < Answer.size(); i++) {
        cout << Answer[i].X << " " << Answer[i].Y << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}