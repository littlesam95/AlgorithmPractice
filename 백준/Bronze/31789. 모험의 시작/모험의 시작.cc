#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, X, S, C, P;
vector<pair<int, int> > Weapons;
bool Answer;

void input() {
    cin >> N;
    cin >> X >> S;
    for (int i = 0; i < N; i++) {
        cin >> C >> P;
        Weapons.push_back(make_pair(C, P));
    }
}

bool comp(pair<int, int> A, pair<int, int> B) {
    if (A.second == B.second) {
        return (A.first < B.first);
    }

    return (A.second > B.second);
}

void settings() {
    sort(Weapons.begin(), Weapons.end(), comp);
    for (int i = 0; i < N; i++) {
        int Coin = Weapons[i].first;
        int Power = Weapons[i].second;
        if ((Coin <= X) && (Power > S)) {
            Answer = true;
            break;
        }
    }
}

void find_Answer() {
    if (Answer) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}