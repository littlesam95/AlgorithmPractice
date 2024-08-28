#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    cin >> S;
}

void find_Answer() {
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];
        if (Now == 'p') {
            if ((i < (int)S.length() - 1) && (S[i + 1] == 'i')) {
                i++;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        else if (Now == 'k') {
            if ((i < (int)S.length() - 1) && (S[i + 1] == 'a')) {
                i++;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        else if (Now == 'c') {
            if ((i < (int)S.length() - 2) && (S[i + 1] == 'h') && (S[i + 2] == 'u')) {
                i += 2;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
        else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    FASTIO
    input();
    find_Answer();

    return 0;
}