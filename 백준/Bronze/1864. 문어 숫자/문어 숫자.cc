#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;
string S;
unordered_map<char, int> UM;
int Answer;

void init() {
    UM['-'] = 0;
    UM['\\'] = 1;
    UM['('] = 2;
    UM['@'] = 3;
    UM['?'] = 4;
    UM['>'] = 5;
    UM['&'] = 6;
    UM['%'] = 7;
    UM['/'] = -1;
}

void find_Answer() {
    Answer = 0;
    reverse(S.begin(), S.end());
    for (int i = 0; i < S.size(); i++) {
        int Cur = UM[S[i]] * pow(8, i);
        Answer += Cur;
    }
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> S;
        if (S == "#") {
            break;
        }
        find_Answer();
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    init();
    input();
    
	return 0;
}