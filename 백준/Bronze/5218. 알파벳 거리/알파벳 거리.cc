#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
string A, B;
vector<int> Vec;

void find_Answer() {
    Vec.clear();
    for (int i = 0; i < A.size(); i++) {
        int C = A[i] - 'A';
        int D = B[i] - 'A';
        if (C <= D) {
            Vec.push_back(D - C);
        }
        else {
            Vec.push_back(D + 26 - C);
        }
    }
    cout << "Distances:";
    for (int i = 0; i < Vec.size(); i++) {
        cout << " " << Vec[i];
    }
    cout << "\n";
}

void input() {
    cin >> T;
    while (T--) {
        cin >> A >> B;
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