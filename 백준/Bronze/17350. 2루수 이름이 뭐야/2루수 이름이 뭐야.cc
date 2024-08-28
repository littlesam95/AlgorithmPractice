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
    while (N--) {
        cin >> S;
        if (S == "anj") {
            Answer = true;
        }
    };
    if (Answer) {
        cout << "뭐야;\n";
    }
    else {
        cout << "뭐야?\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}