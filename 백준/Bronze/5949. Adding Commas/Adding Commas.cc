#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string N;
string Answer;

void input() {
    cin >> N;
    reverse(N.begin(), N.end());

    for (int i = 0; i < (int)N.length(); i++) {
        if ((i != 0) && (i % 3 == 0)) {
            Answer += ",";
        }
        Answer += N[i];
    }
    reverse(Answer.begin(), Answer.end());

    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}