#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 31

using namespace std;
string S;

void Input() {
    cin >> S;
}

void Find_Answer() {
    if (S == "A+") {
        cout << "4.3\n";
    }
    else if (S == "A0") {
        cout << "4.0\n";
    }
    else if (S == "A-") {
        cout << "3.7\n";
    }
    else if (S == "B+") {
        cout << "3.3\n";
    }
    else if (S == "B0") {
        cout << "3.0\n";
    }
    else if (S == "B-") {
        cout << "2.7\n";
    }
    else if (S == "C+") {
        cout << "2.3\n";
    }
    else if (S == "C0") {
        cout << "2.0\n";
    }
    else if (S == "C-") {
        cout << "1.7\n";
    }
    else if (S == "D+") {
        cout << "1.3\n";
    }
    else if (S == "D0") {
        cout << "1.0\n";
    }
    else if (S == "D-") {
        cout << "0.7\n";
    }
    else if (S == "F") {
        cout << "0.0\n";
    }
}

int main(void) {
    Input();
    Find_Answer();
    
    return 0;
}