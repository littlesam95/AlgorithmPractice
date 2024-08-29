#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N;
string S;

void find_Answer() {
    if ((S[0] >= 'a') && (S[0] <= 'z')) {
        S[0] -= 32;
    }
    cout << S << "\n";
}

void input() {
    cin >> N;
    cin.ignore();
    while (N--) {
        getline(cin, S);  
        find_Answer();                
    };
}

int main() {
    FASTIO
    input();

    return 0;
}