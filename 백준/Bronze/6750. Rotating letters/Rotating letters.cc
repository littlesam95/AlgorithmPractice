#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
string S;
set<char> Set {'I', 'O', 'S', 'H', 'Z', 'X', 'N'};

void input() {
    cin >> S;
    for (int i = 0; i < (int)S.length(); i++) {
        char Now = S[i];
        if (Set.find(Now) == Set.end()) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    FASTIO
    input();

    return 0;
}