#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
vector<pair<int, int> > Vec(8);
int Answer;
vector<int> Quiz;

void input() {
    for (int i = 0; i < 8; i++) {
        cin >> Vec[i].first;
        Vec[i].second = i + 1;
    }
}

bool comp(pair<int, int> A, pair<int, int> B) {
    return (A.first > B.first);
}

void settings() {
    sort(Vec.begin(), Vec.end(), comp);
    for (int i = 0; i < 5; i++) {
        Answer += Vec[i].first;
        Quiz.push_back(Vec[i].second);
    }
    sort(Quiz.begin(), Quiz.end());
}

void find_Answer() {
    cout << Answer << "\n";
    for (int i = 0; i < 5; i++) {
        cout << Quiz[i] << " ";
    }
    cout << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}