#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T;
string S;

void input() {
    cin >> T;
    while (T--) {
        cin >> S;

        int A = 0;
        string tmp = "";
        for (int i = 0; i < (int)S.length(); i++) {
            if (S[i] == ',') {
                A = stoi(tmp);
                tmp = "";
            }
            else {
                tmp += S[i];
            }
        }

        cout << A + stoi(tmp) << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}