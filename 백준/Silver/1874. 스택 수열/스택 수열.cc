#include <iostream>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int*stackArr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> stackArr[i];
	}

	stack<int> st;
	int number = 1;
	char*result = new char[(n * 2)];
	int index = 0;
	bool res = true;
	for (int i = 0; i < n; i++) {
		if (st.size() == 0) {
			while (number <= stackArr[i]) {
				st.push(number);
				number++;
				result[index++] = '+';
			};
			st.pop();
			result[index++] = '-';;
		}
		else {
			if (stackArr[i] > stackArr[i - 1]) {
				while (number <= stackArr[i]) {
					st.push(number);
					number++;
					result[index++] = '+';
				};
				st.pop();
				result[index++] = '-';;
			}
			else if (stackArr[i] < stackArr[i - 1]) {
				if (st.top() == stackArr[i]) {
					st.pop();
					result[index++] = '-';;
				}
				else {
					res = false;
					break;
				}
			}
		}
	}

	if (res) {
		for (int i = 0; i < index; i++) {
			cout << result[i] << "\n";
		}
	}
	else {
		cout << "NO";
	}

	return 0;
}