#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
string S;
int Answer;

void input() {
    cin.ignore();
    while (1) {
        getline(cin, S);
        if (S == "#") {
            break;
        }
        Answer = 0;
        for (int i = 0; i < S.size(); i++) {
            char Cur = S[i];
            if ((Cur == 'A') || (Cur == 'E') || (Cur == 'I') || (Cur == 'O') || (Cur == 'U') || 
                (Cur == 'a') || (Cur == 'e') || (Cur == 'i') || (Cur == 'o') || (Cur == 'u')) {
                    Answer++;
            }
        }
        cout << Answer << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}