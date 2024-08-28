#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define LL long long
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S, tmp;
LL Answer;

void input() {
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++) {
        char Now = S[i];
        if ((Now >= '0') && (Now <= '9')) {
            tmp += Now;
        }
        else {
            if ((tmp != "") && ((int)tmp.length() <= 6)) {
                Answer += stoll(tmp);
            }
            tmp = "";
        }
    }
    if ((tmp != "") && ((int)tmp.length() <= 6)) {
        Answer += stoll(tmp);
    }
    tmp = "";
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}