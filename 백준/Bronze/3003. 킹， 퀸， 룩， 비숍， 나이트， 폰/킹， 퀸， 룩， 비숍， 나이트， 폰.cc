#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

using namespace std;
int A, B, C, D, E, F;

int main() {
	FIRST;
    cin >> A >> B >> C >> D >> E >> F;
    cout << 1 - A << " " << 1 - B << " " << 2 - C << " " << 2 - D << " " << 2 - E << " " << 8 - F << "\n";
    
	return 0;
}