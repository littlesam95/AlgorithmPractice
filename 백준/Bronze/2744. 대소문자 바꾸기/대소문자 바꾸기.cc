#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string S;

void Input() {
    cin >> S;    
}

void Settings() {
    for (int i = 0; i < S.size(); i++) {
        if ((S[i] >= 65) && (S[i] <= 90)) {
            S[i] += 32;
        }
        else if ((S[i] >= 97) && (S[i] <= 122)) {
            S[i] -= 32;
        }
    }
}

void Find_Answer() {
    cout << S << "\n";
}

int main(void) {
    Input();
    Settings();
    Find_Answer();
    
    return 0;
}