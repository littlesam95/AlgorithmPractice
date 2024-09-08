#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int T;
string S;

void input() {
    cin >> T;
    while (T--) {
        cin >> S;
        reverse(S.begin(), S.end());
        int N = S[0] - '0';
        if (N % 2 == 0) {
            cout << "even\n";
        }
        else {
            cout << "odd\n";
        }
    };
}

int main(void) {
    input();
    
    return 0;
}