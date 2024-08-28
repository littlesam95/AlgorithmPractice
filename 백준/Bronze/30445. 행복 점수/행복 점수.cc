#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string Text;
int H, A, P, Y, S, D;
double Happy, Sad;

void input() {
    getline(cin, Text);
}

void settings() {
    for (int i = 0; i < (int)Text.length(); i++) {
        char Now = Text[i];
        if (Now == 'H') {
            H++;
        }
        else if (Now == 'A') {
            A++;
        }
        else if (Now == 'P') {
            P++;
        }
        else if (Now == 'Y') {
            Y++;
        }
        else if (Now == 'S') {
            S++;
        }
        else if (Now == 'D') {
            D++;
        }
    }
    Happy = H + A + P + Y;
    Sad = S + A + D;
}

void find_Answer() {
    cout << fixed;
    cout.precision(2);
    if ((Happy == 0) && (Sad == 0)) {
        cout << "50.00\n";
        return;
    }
    cout << round(Happy / (Happy + Sad) * 10000) / 100 << "\n";
}

int main() {
    FASTIO
    input();
    settings();
    find_Answer();

    return 0;
}