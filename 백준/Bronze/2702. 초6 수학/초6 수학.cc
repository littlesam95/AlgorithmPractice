#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T, A, B;
pair<int, int> Answer;

void settings() {
    int a = A;
    int b = B;
    while (1) {
        int R = a % b;
        if (R == 0) {
            Answer.first = b;
            break;
        }
        a = b;
        b = R;
    };
    Answer.second = (A * B) / Answer.first;
}

void find_Answer() {
    cout << Answer.second << " " << Answer.first << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> A >> B;
        settings();
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