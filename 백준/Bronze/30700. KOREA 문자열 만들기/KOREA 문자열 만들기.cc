#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 5
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
char KOREA[MAX] = { 'K','O','R','E','A' };
int Answer;

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];
        if (Now == KOREA[Answer % 5]) {
            Answer++;
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}