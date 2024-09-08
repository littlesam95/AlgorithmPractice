#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 50001
#define LL long long
#define INF 1e9

using namespace std;
int K;
string S1, S2;

/*
	1. 알파벳 대문자, 소문자 구별X : 소문자로 통일
	2. 공백이 하나 이상이라면 크기는 관계X : 공백이 있다면 한 칸으로 통일
	3. 문자열의 맨 앞 혹은 맨 뒤에 나타나는 공백은 있으나 없으니 상관X : 없앰
	4. 특수 부호의 바로 앞이나 바로 뒤에 나오는 공백도 있으나 없으나 상관X : 없앰
	5. 여는 괄호끼리 종류 구별 X : '('로 통일
	6. 닫는 괄호끼리는 종류 구별 X : ')'로 통일
	7. 쉼표와 세미콜론은 구별 X : 쉼표로 통일
*/

string Func(string S) {
	string res = S;
	// 1, 2, 5, 6, 7번 작업
	int spaceStart = -1;
	int spaceEnd = -1;
	for (int i = 0; i < res.size(); i++) {
		if (spaceStart == -1) {
			if ((res[i] >= 'A') && (res[i] <= 'Z')) {
				res[i] += 32;
			}
			else if ((res[i] == '[') || (res[i] == '{')) {
				res[i] = '(';
			}
			else if ((res[i] == ']') || (res[i] == '}')) {
				res[i] = ')';
			}
			else if (res[i] == ';') {
				res[i] = ',';
			}
			else if (res[i] == ' ') {
				spaceStart = i;
			}
		}
		else {
			if (res[i] != ' ') {
				spaceEnd = i - 1;
				if (spaceStart != spaceEnd) {
					int Sub = spaceEnd - spaceStart;
					while (Sub--) {
						res.erase(res.begin() + spaceStart);
						i--;
					};
				}
				i--;
				spaceStart = -1;
				spaceEnd = -1;
			}
		}
	}
	// 3번 작업
	for (int i = 0; i < res.size(); i++) {
		if (res[i] == ' ') {
			res.erase(res.begin() + i);
			i--;
		}
		else {
			break;
		}
	}
	for (int i = (res.size() - 1); i >= 0; i--) {
		if (res[i] == ' ') {
			res.pop_back();
		}
		else {
			break;
		}
	}
	// 4번 작업
	for (int i = 0; i < res.size(); i++) {
		if ((res[i] == '(') || (res[i] == ')') || (res[i] == '[') || (res[i] == ']') || (res[i] == '{') ||
			(res[i] == '}') || (res[i] == '.') || (res[i] == ',') || (res[i] == ';') || (res[i] == ':')) {
			if ((i > 0) && (res[i - 1] == ' ')) {
				res.erase(res.begin() + (i - 1));
				i--;
			}
			if ((i < (res.size() - 1)) && (res[i + 1] == ' ')) {
				res.erase(res.begin() + (i + 1));
			}
		}
	}
	return res;
}

bool isSame(string A, string B) {
	if (A == B) {
		return true;
	}
	return false;
}

void Find_Answer(int Number, bool Flag) {
	if (Flag) {
		cout << "Data Set " << Number << ": equal\n";
		cout << "\n";
	}
	else {
		cout << "Data Set " << Number << ": not equal\n";
		cout << "\n";
	}
}

void Input() {
	cin >> K;
	cin.ignore();
	for (int i = 1; i <= K; i++) {
		getline(cin, S1);
		getline(cin, S2);
		bool Flag = isSame(Func(S1), Func(S2));
		Find_Answer(i, Flag);
	}
}

int main() {
	FASTIO
	Input();

	return 0;
}