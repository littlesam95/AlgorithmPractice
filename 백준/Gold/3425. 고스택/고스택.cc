#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define LL long long
#define INF 1e9

using namespace std;
int N;
bool Flag;
vector<string> Query;
vector<LL> Stack;
vector<string> answer;

void init() {
	Flag = true;
	Query.clear();
	answer.clear();
}

bool Command_Play() {
	for (int i = 0; i < Query.size(); i++) {
		string cmd = Query[i];
		int size = Stack.size();
		if (cmd.substr(0, 3) == "NUM") {
			// X를 스택의 가장 위에 저장한다.
			LL X = stoll(cmd.substr(4));
			Stack.push_back(X);
		}
		else if (cmd == "POP") {
			// 스택 가장 위의 숫자를 제거한다. 스택이 비어있는데 이 명령어가 나온다면 에러이다.
			if (Stack.size() > 0) {
				Stack.erase(Stack.begin() + (size - 1));
			}
			else {
				return false;
			}
		}
		else if (cmd == "INV") {
			// 스택 가장 위의 숫자의 부호를 바꾼다. 스택이 비어있는데 이 명령어가 나온다면 에러이다.
			if (Stack.size() > 0) {
				Stack[size - 1] = -Stack[size - 1];
			}
			else {
				return false;
			}
		}
		else if (cmd == "DUP") {
			// 스택 가장 위의 숫자를 하나 더 스택에 저장한다. 스택이 비어있는데 이 명령어가 나온다면 에러이다.
			if (Stack.size() > 0) {
				Stack.push_back(Stack[size - 1]);
			}
			else {
				return false;
			}
		}
		else if (cmd == "SWP") {
			// 첫 번째와 두 번째 숫자를 바꾼다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL tmp = Stack[size - 1];
				Stack[size - 1] = Stack[size - 2];
				Stack[size - 2] = tmp;
			}
			else {
				return false;
			}
		}
		else if (cmd == "ADD") {
			// 첫 번째와 두 번째 숫자를 더한다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(B + A) <= INF) {
					// 연산 결과의 절댓값이 10^9을 넘어간다면 에러이다.
					Stack.push_back(B + A);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "SUB") {
			// 첫 번째와 두 번째 숫자를 뺀다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(B - A) <= INF) {
					// 연산 결과의 절댓값이 10^9을 넘어간다면 에러이다.
					Stack.push_back(B - A);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "MUL") {
			// 첫 번째와 두 번째 숫자를 곱한다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (abs(A * B) <= INF) {
					// 연산 결과의 절댓값이 10^9을 넘어간다면 에러이다.
					Stack.push_back(A * B);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "DIV") {
			// 첫 번째와 두 번째 숫자를 나눈다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (A != 0) {
					if (A > 0) {
						if (B >= 0) {
							Stack.push_back(B / A);
						}
						else {
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(-R);
						}
					}
					else if (A < 0) {
						if (B >= 0) {
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(-R);
						}
						else {
							A = abs(A);
							B = abs(B);
							LL R = B / A;
							Stack.push_back(R);
						}
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else if (cmd == "MOD") {
			// 첫 번째와 두 번째 숫자를 나눈 나머지를 저장한다. 스택에 숫자가 1개 이하일 때 이 명령어가 나온다면 에러이다.
			if (Stack.size() >= 2) {
				LL A = Stack[size - 1];
				LL B = Stack[size - 2];
				Stack.erase(Stack.begin() + (size - 1));
				Stack.erase(Stack.begin() + (size - 2));
				if (A != 0) {
					if (B >= 0) {
						A = abs(A);
						B = abs(B);
						LL R = B % A;
						Stack.push_back(R);
					}
					else {
						A = abs(A);
						B = abs(B);
						LL R = B % A;
						Stack.push_back(-R);
					}
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {
	FIRST
	while (1) {
		init();
		while (1) {
			string cmd;
			getline(cin, cmd);
			if (cmd == "END") {
				break;
			}
			if (cmd == "QUIT") {
				Flag = false;
				break;
			}
			Query.push_back(cmd);
		};
		if (!Flag) {
			break;
		}
		cin >> N;
		for (int i = 0; i < N; i++) {
			Stack.clear();
			int V;
			cin >> V;
			Stack.push_back(V);
			bool res = Command_Play();
			if (res) {
				if (Stack.size() == 1) {
					cout << Stack[0] << "\n";
				}
				else {
					cout << "ERROR" << "\n";
				}
			}
			else {
				cout << "ERROR" << "\n";
			}
		}
		cout << "\n";
	};

	return 0;
}