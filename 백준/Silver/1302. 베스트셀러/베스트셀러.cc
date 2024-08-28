#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
unordered_map<string, int> Books;
vector<pair<string, int> > Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        Books[S]++;
    }
}

bool comp(pair<string, int> X, pair<string, int> Y) {
    if (X.second == Y.second) {
        return (X.first < Y.first);
    }

    return (X.second > Y.second);
}

void settings() {
    for (auto IT : Books) {
        Answer.push_back(make_pair(IT.first, IT.second));
    }
    sort(Answer.begin(), Answer.end(), comp);
}

void find_Answer() {
    cout << Answer[0].first << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}