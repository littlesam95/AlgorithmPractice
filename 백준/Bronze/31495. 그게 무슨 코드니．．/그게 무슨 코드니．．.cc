#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    getline(cin, S);
    int Len = (int)S.length();
    if ((S[0] == '\"') && (S[Len - 1] == '\"')) {
        string Answer = S.substr(1, Len - 2);
        if (Answer.empty()) {
            cout << "CE\n";
        }
        else {
            cout << Answer << "\n";
        }
    }
    else {
        cout << "CE\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}