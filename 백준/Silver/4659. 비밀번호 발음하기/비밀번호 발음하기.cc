#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 26
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
bool isEvenAplha[MAX];
int odd_count, even_count;
bool isEven;
bool Answer;

void init() {
    isEvenAplha['a' - 'a'] = true;
    isEvenAplha['e' - 'a'] = true;
    isEvenAplha['i' - 'a'] = true;
    isEvenAplha['o' - 'a'] = true;
    isEvenAplha['u' - 'a'] = true;

    odd_count = 0;
    even_count = 0;
    isEven = false;
    Answer = true;
}

void settings() {
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];

        if (isEvenAplha[Now - 'a']) {
            isEven = true;
            odd_count = 0;
            even_count++;
        }
        else {
            even_count = 0;
            odd_count++;
        }

        if ((odd_count >= 3) || (even_count >= 3)) {
            Answer = false;
        }

        if (i < ((int)S.length() - 1) && (Now == S[i + 1])) {
            if ((Now != 'e') && (Now != 'o')) {
                Answer = false;
            }
        }
    }

    if (!isEven) {
        Answer = false;
    }
}

void find_Answer() {
    if (Answer) {
        cout << "<" << S << "> is acceptable.\n";
    }
    else {
        cout << "<" << S << "> is not acceptable.\n";
    }
}

void input() {
    while (1) {
        init();
        cin >> S;
        if (S == "end") {
            break;
        }
        settings();
        find_Answer();
    };
}

int main() {
    FASTIO
    input();

    return 0;
}