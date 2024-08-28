#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, M;
vector<pair<string, string> > Infos;
string S;
string Answer;

bool comp(pair<string, string> A, pair<string, string> B) {
    return (A.first < B.first);
}

void settings() {
    Answer = "";

    for (int i = 0; i < (int)S.length(); i++) {
        for (int j = 0; j < (int)Infos.size(); j++) {
            int len = Infos[j].first.length();
            if ((int)S.length() - i < len) {
                continue;
            }
            string Now = S.substr(i, len);
            if (Now == Infos[j].first) {
                Answer += Infos[j].second;
            }
        }
    }
}

void find_Answer() {
    if (Answer == "") {
        cout << "-1\n";
        return;
    }
    cout << Answer << "\n";
}

void input() {
    cin >> N >> M;
    Infos.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Infos[i].first >> Infos[i].second;
    }
    sort(Infos.begin(), Infos.end(), comp);
    for (int i = 0; i < M; i++) {
        cin >> S;
        settings();
        find_Answer();
    }
}

int main() {
    FASTIO
    input();

    return 0;
}