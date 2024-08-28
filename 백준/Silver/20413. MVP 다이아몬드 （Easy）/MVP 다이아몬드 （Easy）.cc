#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, S, G, P, D, Prev;
string MVP;
int Answer;

void input() {
    cin >> N;
    cin >> S >> G >> P >> D;
    cin >> MVP;
}

void settings() {
    for (int i = 0; i < N; i++) {
        char Now = MVP[i];
        if (Now == 'B') {
            int Next = max((S - 1 - Prev), 0);
            Answer += Next;
            Prev = Next;
        }
        else if (Now == 'S') {
            int Next = max((G - 1 - Prev), 0);
            Answer += Next;
            Prev = Next;
        }
        else if (Now == 'G') {
            int Next = max((P - 1 - Prev), 0);
            Answer += Next;
            Prev = Next;
        }
        else if (Now == 'P') {
            int Next = max((D - 1 - Prev), 0);
            Answer += Next;
            Prev = Next;
        }
        else {
            Answer += D;
            Prev = D;
        }
    }
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