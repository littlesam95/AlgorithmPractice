#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define LL long long
#define INF 2e9
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct POINT {
	LL X, Y;

	bool operator<(const POINT &A) const {
		if (X != A.X) return (X < A.X);

		return (Y < A.Y);
	}
};

int N;
LL L, X, Y, MinX, MinY, FirstPoint;
LL MoveX[4] = { 0,-1,0,1 };
LL MoveY[4] = { -1,0,1,0 };
vector<POINT> Points, CV;
double Answer;

void init() {
	MinX = INF;
	MinY = INF;
}

LL get_Distance(POINT A, POINT B) {
	return (A.X - B.X) * (A.X - B.X) + (A.Y - B.Y) * (A.Y - B.Y);
}

LL get_CCW(POINT A, POINT B, POINT C) {
	LL OP = (A.X * B.Y) + (B.X * C.Y) + (C.X * A.Y);
	OP -= ((A.Y * B.X) + (B.Y * C.X) + (C.Y * A.X));

	return OP;
}

bool comp(POINT A, POINT B) {
	LL NowCCW = get_CCW(Points[0], A, B);

	if (NowCCW != 0) return (NowCCW > 0);
	if (A.X != B.X) return (A.X < B.X);
	return (A.Y < B.Y);
}

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		for (int j = 0; j < 4; j++) {
			LL NextX = X + (MoveX[j] * L);
			LL NextY = Y + (MoveY[j] * L);
			Points.push_back({ NextX,NextY });
		}
	}
}

void graham_Scan() {
	for (int i = 0; i < (int)Points.size(); i++) {
		if ((MinX > Points[i].X) || ((MinX == Points[i].X) && (MinY > Points[i].Y))) {
			MinX = Points[i].X;
			MinY = Points[i].Y;
			FirstPoint = i;
		}
	}
	swap(Points[0], Points[FirstPoint]);
	sort(Points.begin() + 1, Points.end(), comp);
	for (int i = 0; i < (int)Points.size(); i++) {
		while (((int)CV.size() >= 2) && (get_CCW(Points[i], CV[(int)CV.size() - 2], CV[(int)CV.size() - 1]) <= 0)) {
			CV.pop_back();
		}
		CV.push_back(Points[i]);
	}
	for (int i = 1; i < (int)CV.size(); i++) {
		Answer += sqrt(get_Distance(CV[i - 1], CV[i]));
	}
	Answer += sqrt(get_Distance(CV[(int)CV.size() - 1], CV[0]));
}

void find_Answer() {
	cout << fixed;
	cout.precision(10);
	cout << Answer << "\n";
}

void settings() {
	init();
	graham_Scan();
}

int main() {
	FASTIO
	input();
	settings();
	find_Answer();

	return 0;
}