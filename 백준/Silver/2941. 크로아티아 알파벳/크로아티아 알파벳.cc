#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1000

using namespace std;
string Word;
int answer = 0;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> Word;
    for (int i = 0; i < Word.size(); i++) {
        char Cur = Word[i];
        if (Cur == 'c') {
            if (Word[i + 1] == '=') {
                i++;
            }
            else if (Word[i + 1] == '-') {
                i++;
            }
        }
        else if (Cur == 'd') {
            if (Word[i + 1] == 'z') {
                if (Word[i + 2] == '=') {
                    i++;
                    i++;
                }
            }
            else if (Word[i + 1] == '-') {
                i++;
            }
        }
        else if (Cur == 'l') {
            if (Word[i + 1] == 'j') {
                i++;
            }
        }
        else if (Cur == 'n') {
            if (Word[i + 1] == 'j') {
                i++;
            }
        }
        else if (Cur == 's') {
            if (Word[i + 1] == '=') {
                i++;
            }
        }
        else if (Cur == 'z') {
            if (Word[i + 1] == '=') {
                i++;
            }
        }
        answer++;
    }
    cout << answer << "\n";
    
    return 0;
}