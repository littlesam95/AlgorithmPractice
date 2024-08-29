#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int T, A, B, C;
vector<string> Answer;

void input() {
    cin >> T;
    while (T--) {
        cin >> A >> B >> C;
        if (((A < B) && (B < C)) || ((A > B) && (B > C))) {
            Answer.push_back("Ordered");
        }
        else {
            Answer.push_back("Unordered");
        }
    };
    cout << "Gnomes:\n";
    for (int i = 0; i < Answer.size(); i++) {
        cout << Answer[i] << "\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}