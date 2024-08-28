#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
vector<string> Vec;
vector<string> New;
int Answer;

void input() {
    cin >> N;
    Vec.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Vec[i];
    }
}

bool comp(string A, string B) {
    return (A > B);
}

void settings() {
    New = Vec;
    sort(New.begin(), New.end());

    if (Vec == New) {
        Answer = 1;
        return;
    }

    sort(New.begin(), New.end(), comp);

    if (Vec == New) {
        Answer = 2;
        return;
    }

    Answer = -1;
}

void find_Answer() {
    if (Answer == 1) {
        cout << "INCREASING\n";
    }
    else if (Answer == 2) {
        cout << "DECREASING\n";
    }
    else {
        cout << "NEITHER\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}