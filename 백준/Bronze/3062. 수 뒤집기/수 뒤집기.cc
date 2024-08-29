#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
string N;

void input() {
    cin >> T;
    while (T--) {
        cin >> N;
        string R = N;
        reverse(R.begin(), R.end());
        int S = stoi(N) + stoi(R);
        string A = to_string(S);
        string B = A;
        reverse(B.begin(), B.end());
        if (A == B) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    
	return 0;
}