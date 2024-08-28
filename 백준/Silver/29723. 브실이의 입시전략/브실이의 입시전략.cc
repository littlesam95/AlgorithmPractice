#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M, K, P;
string S;
unordered_map<string, int> Lectures;
unordered_map<string, int> Checked;
vector<pair<string, int> > Vec;
int sum_Score = 0;
int AnswerA, AnswerB = 0;

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> S >> P;
        Lectures[S] = P;
    }
    for (int i = 0; i < K; i++) {
        cin >> S;
        Checked[S] = 1;
        sum_Score += Lectures[S];
    }
}

bool comp1(pair<string, int> X, pair<string, int> Y) {
    if (X.second == Y.second) {
        return (X.first < Y.first);
    }

    return (X.second < Y.second);
}

bool comp2(pair<string, int> X, pair<string, int> Y) {
    if (X.second == Y.second) {
        return (X.first < Y.first);
    }

    return (X.second > Y.second);
}

void settings() {
    for (auto IT : Lectures) {
        if (Checked[IT.first] != 1) {
            Vec.push_back(make_pair(IT.first, IT.second));
        }
    }
    sort(Vec.begin(), Vec.end(), comp1);
    AnswerA = sum_Score;
    for (int i = 0; i < (M - K); i++) {
        AnswerA += Vec[i].second;
    }
    sort(Vec.begin(), Vec.end(), comp2);
    AnswerB = sum_Score;
    for (int i = 0; i < (M - K); i++) {
        AnswerB += Vec[i].second;
    }
}

void find_Answer() {
    cout << AnswerA << " " << AnswerB << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}