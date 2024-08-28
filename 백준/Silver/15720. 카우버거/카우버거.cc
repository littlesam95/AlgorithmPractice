#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int B, C, D;
vector<int> Burgers, Sides, Beverages;
int AnswerA, AnswerB;

void input() {
    cin >> B >> C >> D;
    Burgers.resize(B);
    Sides.resize(C);
    Beverages.resize(D);
    for (int i = 0; i < B; i++) {
        cin >> Burgers[i];
        AnswerA += Burgers[i];
    }
    for (int i = 0; i < C; i++) {
        cin >> Sides[i];
        AnswerA += Sides[i];
    }
    for (int i = 0; i < D; i++) {
        cin >> Beverages[i];
        AnswerA += Beverages[i];
    }
}

bool comp(int X, int Y) {
    return (X > Y);
}

void settings() {
    sort(Burgers.begin(), Burgers.end(), comp);
    sort(Sides.begin(), Sides.end(), comp);
    sort(Beverages.begin(), Beverages.end(), comp);

    for (int i = 0; i < min(min(B, C), D); i++) {
        AnswerB += (Burgers[i] + Sides[i] + Beverages[i]) * 9 / 10;
    }
    for (int i = min(min(B, C), D); i < B; i++) {
        AnswerB += Burgers[i];
    }
    for (int i = min(min(B, C), D); i < C; i++) {
        AnswerB += Sides[i];
    }
    for (int i = min(min(B, C), D); i < D; i++) {
        AnswerB += Beverages[i];
    }
}

void find_Answer() {
    cout << AnswerA << "\n" << AnswerB << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}