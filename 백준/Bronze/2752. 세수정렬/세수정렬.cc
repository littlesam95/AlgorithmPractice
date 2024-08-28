#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int Number[3];

int main() {
	FIRST;
    for (int i = 0; i < 3; i++) {
        cin >> Number[i];
    }
    sort(Number, Number + 3);
    cout << Number[0] << " " << Number[1] << " " << Number[2] << "\n";
    
	return 0;
}