#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
string Answer;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        int upper_count = 0;
        int lower_count = 0;
        int hype = 0;
        for (int j = 0; j < (int)S.length(); j++) {
            char Now = S[j];
            if ((Now >= 'a') && (Now <= 'z')) {
                lower_count++;
            }
            else if ((Now >= 'A') && (Now <= 'Z')) {
                upper_count++;
            }
            else if (Now == '-') {
                hype++;
            }
        }
        if (upper_count > lower_count) {
            continue;
        }
        if ((int)S.length() > 10) {
            continue;
        }
        if ((upper_count + lower_count + hype) == 0) {
            continue;
        }
        Answer = S;
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}