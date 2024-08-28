#include <iostream>
#include <string>
#include <algorithm>
#define MAX 26

using namespace std;
int N;
int Arr[MAX];
string Word;
int answer = 0;

void init() {
    for (int i = 0; i < MAX; i++) {
        Arr[i] = 0;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> N;
    while (N--) {
        init();
        cin >> Word;
        bool Flag = true;
        for (int i = 0; i < Word.size(); i++) {
            if(Arr[Word[i] - 'a'] == 0) {
                Arr[Word[i] - 'a']++;
                int Start = i;
                for (int j = Start + 1; j < Word.size(); j++) {
                    if (Word[Start] == Word[j]) {
                        Arr[Word[Start] - 'a']++;
                        i = j;
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                Flag = false;
                break;
            }
        }
        if (Flag) {
            answer++;
        }
    };
    cout << answer << "\n";
    
    return 0;
}