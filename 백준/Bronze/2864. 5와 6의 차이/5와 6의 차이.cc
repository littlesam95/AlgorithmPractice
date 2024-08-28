#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string A, B;
int Max, Min;

void input() {
    cin >> A >> B;
}

void settings() {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '6') {
            A[i] = '5';
        }
    }
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == '6') {
            B[i] = '5';
        }
    }
    Min = stoi(A) + stoi(B);
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == '5') {
            A[i] = '6';
        }
    }
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == '5') {
            B[i] = '6';
        }
    }
    Max = stoi(A) + stoi(B);
}

void find_Answer() {
    cout << Min << " " << Max << "\n";
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    input();
    settings();
    find_Answer();
    
	return 0;
}