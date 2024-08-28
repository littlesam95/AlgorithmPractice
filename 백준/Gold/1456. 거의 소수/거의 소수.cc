#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#define MAX 10000001
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
LL DP[MAX];
LL A, B;
set<LL> S;

void init() {
    for (int i = 2; i < MAX; i++) {
        DP[i] = i;
    }
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (DP[i] == 0) {
            continue;
        }
        for (int j = (i * i); j < MAX; j += i) {
            DP[j] = 0;
        }
    }
}

void input() {
    cin >> A >> B;
}

void settings() {
    LL R = 2;
    while (1) {
        LL NewA = (LL)floor(pow((double)A, 1.0 / (double)R));
        LL NewB = (LL)floor(pow((double)B, 1.0 / (double)R));
        for (LL i = NewA; i <= (NewB + 1); i++) {
            if (DP[i] == i) {
                LL Now = (LL)pow((double)i, (double)R);
                if ((Now >= A) && (Now <= B)) {
                    S.insert(Now);
                }
            }
        }
        if ((NewA == 1) && (NewB == 1)) {
            break;
        }
        else {
            R++;
        }
    };
}

void find_Answer() {
    cout << (LL)S.size() << "\n";
}

int main() {
    FASTIO
    init();
    input();
    settings();
    find_Answer();

    return 0;
}