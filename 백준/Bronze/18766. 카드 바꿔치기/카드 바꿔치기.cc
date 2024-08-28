#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T, N;
vector<string> Card, NewCard;

void find_Answer() {
    Card.clear();
    NewCard.clear();
    cin >> N;
    Card.resize(N);
    NewCard.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Card[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> NewCard[i];
    }
    sort(Card.begin(), Card.end());
    sort(NewCard.begin(), NewCard.end());
    for (int i = 0; i < N; i++) {
        if (Card[i] != NewCard[i]) {
            cout << "CHEATER\n";
            return;
        }
    }
    cout << "NOT CHEATER\n";
}

void input() {
    cin >> T;
    while (T--) {
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}