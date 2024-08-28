#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, A, S;
LL B, M;
vector<LL> Presents;
int Answer = -1;

void input() {
    cin >> N >> B >> A;
    Presents.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> Presents[i];
    }
}

void settings() {
    sort(Presents.begin(), Presents.end());
    for (int i = 0; i < A; i++) {
        int Now = (Presents[i] / 2);
        if ((M + Now) <= B) {
            M += Now;
        }
        else {
            Answer = i;
            break;
        }
    }

    if (Answer == -1) {
        Answer = A;
        for (int i = A; i < N; i++) {
            int First = (Presents[S] / 2);
            int Now = (Presents[i] / 2);
            if ((M + First + Now) <= B) {
                M += (First + Now);
                Answer++;
                S++;
            }
            else {
                break;
            }
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