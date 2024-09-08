#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
string S;

void find_Answer() {
    if (S == "P=NP") {
        cout << "skipped\n";
    }
    else {
        int A, B;
        string tmp = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '+') {
                A = stoi(tmp);
                tmp = "";
            }
            else {
                tmp += S[i];
            }
        }
        B = stoi(tmp);
        cout << A + B << "\n";
    }
}

void input() {
    cin >> N;
    while (N--) {
        cin >> S;
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