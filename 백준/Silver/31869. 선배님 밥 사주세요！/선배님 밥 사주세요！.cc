#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
struct SENPAI {
    string Name;
    int Price;
};

int N, W, D, P;
string S;
vector<pair<int, SENPAI> > Senpais;
unordered_map<string, int> Moneys;
bool Visited[10][7];
int Answer;

bool comp(pair<int, SENPAI> A, pair<int, SENPAI> B) {
    return (A.first < B.first);
}

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> W >> D >> P;
        SENPAI Senpai = { S,P };
        Senpais.push_back(make_pair((W - 1) * 7 + D, Senpai));
    }
    sort(Senpais.begin(), Senpais.end(), comp);
    for (int i = 0; i < N; i++) {
        cin >> S >> P;
        Moneys.insert(make_pair(S, P));
    }
}

void settings() {
    for (int i = 0; i < N; i++) {
        int Week = Senpais[i].first / 7;
        int Day = Senpais[i].first % 7;
        string Name = Senpais[i].second.Name;
        int Price = Senpais[i].second.Price;
        int Money = Moneys[Name];
        if (Money >= Price) {
            Visited[Week][Day] = true;
            Moneys[Name] = -1;
        }
    }

    int Max_Day = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 7; j++) {
            if (Visited[i][j]) {
                Max_Day++;
            }
            else {
                Answer = max(Answer, Max_Day);
                Max_Day = 0;
            }
        }
    }
    Answer = max(Answer, Max_Day);
}

void find_Answer() {
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}