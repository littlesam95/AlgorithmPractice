#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int E, F, C;
int Answer = 0;

void input() {
    cin >> E >> F >> C;
}

void find_Answer() {
    E += F;
    while (1) {
        if (E < C) {
            break;
        }
        int R = E / C;
        Answer += R;
        E %= C;
        E += R;
    };
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