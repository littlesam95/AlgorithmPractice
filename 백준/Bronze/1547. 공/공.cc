#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0);

using namespace std;
int N;
int Arr[3] = { 1, 0, 0 };

void input() {
    cin >> N;
    while (N--) {
        int X, Y;
        cin >> X >> Y;
        swap(Arr[X - 1], Arr[Y - 1]);
    };
    if (Arr[0] == 1) {
        cout << "1\n";
    }
    else if (Arr[1] == 1) {
        cout << "2\n";
    }
    else {
        cout << "3\n";
    }
}

int main() {
    FASTIO
    input();

    return 0;
}