#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int D, M, Y;
int Day[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
int Answer;

void settings() {
    Answer = Day[M - 1];
    Answer += D;
    if (M >= 3) {
        if (Y % 4 == 0) {
            if (Y % 100 != 0) {
                Answer++;
            }
            else {
                if (Y % 400 == 0) {
                    Answer++;
                }
            }
        }
    }
}

void find_Answer() {
    cout << Answer << "\n";
}

void input() {
    while (1) {
        cin >> D >> M >> Y;
        if ((D == 0) && (M == 0) && (Y == 0)) {
            break;
        }
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