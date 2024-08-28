#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
unsigned long long n;
unsigned long long q;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
    q=sqrt(n);
    if(q * q < n) {
        q++;
    }
	cout << q << "\n";

	return 0;
}