#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string N;
int Answer;
int Facto[6] = { 0, 1, 2, 6, 24, 120 };

void find_Answer() {
    reverse(N.begin(), N.end());
    Answer = 0;
    for (int i = 0; i < N.size(); i++) {
        int Cur = N[i] - '0';
        Answer += (Cur * Facto[i + 1]);
    }
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> N;
        if (N == "0") {
            break;
        }
        find_Answer();
    };
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    
	return 0;
}