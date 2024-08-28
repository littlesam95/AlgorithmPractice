#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define MAX 101
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
unordered_map<string, int> Students;
int Popularity[MAX];
vector<pair<string, int> > Answer;

vector<string> split(string X) {
    vector<string> Result;
    string tmp = "";

    for (int i = 0; i < (int)X.size(); i++) {
        if (X[i] == ' ') {
            Result.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += X[i];
        }
    }
    Result.push_back(tmp);

    return Result;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        Students[S] = i + 1;
    }
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, S);
        vector<string> Vec = split(S);
        for (int j = 0; j < (int)Vec.size(); j++) {
            string Now = Vec[j];
            Popularity[Students[Now]]++;
        }
    }
}

bool comp(pair<string, int> X, pair<string, int> Y) {
    if (X.second == Y.second) {
        return (X.first < Y.first);
    }

    return (X.second > Y.second);
}

void settings() {
    for (auto IT : Students) {
        Answer.push_back(make_pair(IT.first, Popularity[IT.second]));
    }
    sort(Answer.begin(), Answer.end(), comp);
}

void find_Answer() {
    for (int i = 0; i < N; i++) {
        cout << Answer[i].first << " " << Answer[i].second << "\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}