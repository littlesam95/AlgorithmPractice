#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;
bool Answer;

void input() {
    cin >> N;
    cin >> S;
    if (N >= 3) {
        for (int i = 0; i < (N - 2); i++) {
            if ((S[i] == 'o') && (S[i] == S[i + 1]) && (S[i + 1] == S[i + 2])) {
                Answer = true;
                break;
            }
        }
    }
    if (Answer) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}