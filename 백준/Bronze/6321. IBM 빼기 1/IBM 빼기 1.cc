#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int T;
string S;

void find_Answer(int Case) {
    cout << "String #" << Case << "\n";
    for (int i = 0; i < S.size(); i++) {
        char Now = S[i];
        if (Now == 'Z') {
            cout << "A";
        }
        else {
            cout << (char)(Now + 1);
        }
    }
    cout << "\n";
}

void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> S;
        find_Answer(i + 1);
        cout << "\n";              
    };
}

int main() {
    FASTIO
    input();

    return 0;
}