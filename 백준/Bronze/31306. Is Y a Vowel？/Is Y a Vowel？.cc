#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
int Even, Y;

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == 'y') {
            Y++;
        }
        else if ((S[i] == 'a') || (S[i] == 'e') || (S[i] == 'i') || (S[i] == 'o') || (S[i] == 'u')) {
            Even++;
        }
    }
    cout << Even << " " << Even + Y << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}