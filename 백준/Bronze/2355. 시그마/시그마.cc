#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define LL long long

using namespace std;
LL A, B, Answer;

void input() {
    cin >> A >> B;
}

void find_Answer() {
    if (A < B) {
        Answer = (B - A + 1) * (A + B) / 2;
    }
    else {
        Answer = (A - B + 1) * (A + B) / 2;
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