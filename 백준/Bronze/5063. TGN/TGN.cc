#include <iostream>
#include <algorithm>

using namespace std;
int N, R, E, C;

void find_Answer() {
    if (R < (E - C)) {
        cout << "advertise\n";
    }
    else if (R == (E - C)) {
        cout << "does not matter\n";
    }
    else {
        cout << "do not advertise\n";
    }
}

void input() {
    cin >> N;
    while (N--) {
        cin >> R >> E >> C;
        find_Answer();
    };
}

int main(void) {
    input();
    
    return 0;
}