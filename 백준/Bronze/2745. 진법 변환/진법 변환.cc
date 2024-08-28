#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
string N;
int B, Answer = 0;

void input() {
    cin >> N >> B;
}

void find_Answer() {
    reverse(N.begin(), N.end());
    for (int i = 0; i < N.size(); i++) {
        int Cur = 0;
        if ((N[i] >= '0') && (N[i] <= '9')) {
            Cur = N[i] - '0';
        }
        else {
            Cur = (N[i] - 'A' + 10);
        }
        int Next = Cur * pow(B, i);
        Answer += Next;
    }
    cout << Answer << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    find_Answer();
    
	return 0;
}