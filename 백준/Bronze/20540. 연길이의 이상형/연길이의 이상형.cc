#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
string Answer;

void input() {
    cin >> S;
    for(int i = 0; i < S.length(); i++){
        if(S[i] == 'E') {
            Answer += 'I';
        }
        else if(S[i] == 'I') {
            Answer += 'E';
        }
        else if(S[i] == 'S') {
            Answer += 'N';
        }
        else if(S[i] == 'N') {
            Answer += 'S';
        }
        else if(S[i] == 'T') {
            Answer += 'F';
        }
        else if(S[i] == 'F') {
            Answer += 'T';
        }
        else if(S[i] == 'P') {
            Answer += 'J';
        }
        else {
            Answer += 'P';
        }
    }
    cout << Answer << "\n";
}

int main() {
    FASTIO
    input();

    return 0;
}