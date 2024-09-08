#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;

void input() {
    while (1) {
        getline(cin, S);
        if (cin.eof()) {
            break;
        }
        for (int i = 0; i < (int)S.size(); i++) {
            switch (S[i]) {
                case 'e':
                    cout << "i";
                    break;
                case 'i':
                    cout << "e";
                    break;
                case 'E':
                    cout << "I";
                    break;
                case 'I':
                    cout << "E";
                    break;
                default:
                    cout << S[i];
                    break;
            }
        }
        cout << "\n";
    };
}

int main() {
    FASTIO
    input();

    return 0;
}