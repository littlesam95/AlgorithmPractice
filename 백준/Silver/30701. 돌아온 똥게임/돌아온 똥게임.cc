#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, M, W;
LL D, X;
vector<LL> Monsters, Weapons;
int Answer;

void input() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> A >> X;
        if (A == 1) {
            Monsters.push_back(X);
        }
        else {
            Weapons.push_back(X);
        }
    }
}

void settings() {
    sort(Monsters.begin(), Monsters.end());
    sort(Weapons.begin(), Weapons.end());
    while (1) {
        if (M < (int)Monsters.size()) {
            if (Monsters[M] < D) {
                D += Monsters[M];
                M++;
                Answer++;
            }
            else {
                if (W < (int)Weapons.size()) {
                    D *= Weapons[W];
                    W++;
                    Answer++;
                }
                else {
                    break;
                }
            }
        }
        else {
            if (W < (int)Weapons.size()) {
                D *= Weapons[W];
                W++;
                Answer++;
            }
            else {
                break;
            }
        }
    };
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