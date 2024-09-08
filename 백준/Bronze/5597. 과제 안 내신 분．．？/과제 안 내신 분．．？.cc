#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 31

using namespace std;
bool visited[MAX];

void Input() {
    for (int i = 0; i < 28; i++) {
        int N;
        cin >> N;
        visited[N] = true;
    }
}

void Find_Answer() {
    for (int i = 1; i <= 30; i++) {
        if (!visited[i]) {
            cout << i << "\n";
        }
    }
}

int main(void) {
    Input();
    Find_Answer();
    
    return 0;
}