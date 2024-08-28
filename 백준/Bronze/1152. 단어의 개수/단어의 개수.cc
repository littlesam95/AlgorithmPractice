#include <iostream>
#include <string>

using namespace std;

int main() {
	string sentence;
	int count = 0;

	do {
		getline(cin, sentence);
	} while ((sentence.length() < 0) || (sentence.length() > 10000000));

	int index = sentence.length();
	for (int i = 0; i < sentence.length(); i++) {
		if (sentence.substr(i, 1) != " ") {
			index = i;
			break;
		}
	}

	for (int i = index; i < sentence.length(); i++) {
		if (sentence.substr(i, 1) == " ") {
			if (sentence.substr(i + 1, 1) != " ") {
				count++;
			}
		}
	}
	if (sentence.substr(sentence.length() - 1, 1) != " ") {
		count++;
	}

	cout << count;

	getchar();
	getchar();
	return 0;
}