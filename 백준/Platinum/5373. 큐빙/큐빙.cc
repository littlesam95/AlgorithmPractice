#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define LL long long
#define INF 1e9

using namespace std;
int T, N;
char MAP[MAX];

void init() {
	for (int i = 1; i <= 9; i++) {
		MAP[i] = 'w';
	}
	for (int i = 10; i <= 18; i++) {
		MAP[i] = 'o';
	}
	for (int i = 19; i <= 27; i++) {
		MAP[i] = 'y';
	}
	for (int i = 28; i <= 36; i++) {
		MAP[i] = 'g';
	}
	for (int i = 37; i <= 45; i++) {
		MAP[i] = 'b';
	}
	for (int i = 46; i <= 54; i++) {
		MAP[i] = 'r';
	}
}

void Left_Back_Rotation() { // 왼쪽 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[4];
	int tmp3 = MAP[7];

	MAP[1] = MAP[54];
	MAP[4] = MAP[51];
	MAP[7] = MAP[48];

	MAP[54] = MAP[19];
	MAP[51] = MAP[22];
	MAP[48] = MAP[25];

	MAP[19] = MAP[10];
	MAP[22] = MAP[13];
	MAP[25] = MAP[16];

	MAP[10] = tmp1;
	MAP[13] = tmp2;
	MAP[16] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[30];
	Tmp_MAP[0][1] = MAP[29];
	Tmp_MAP[0][2] = MAP[28];
	Tmp_MAP[1][0] = MAP[33];
	Tmp_MAP[1][1] = MAP[32];
	Tmp_MAP[1][2] = MAP[31];
	Tmp_MAP[2][0] = MAP[36];
	Tmp_MAP[2][1] = MAP[35];
	Tmp_MAP[2][2] = MAP[34];

	MAP[30] = Tmp_MAP[0][2];
	MAP[29] = Tmp_MAP[1][2];
	MAP[28] = Tmp_MAP[2][2];
	MAP[33] = Tmp_MAP[0][1];
	MAP[32] = Tmp_MAP[1][1];
	MAP[31] = Tmp_MAP[2][1];
	MAP[36] = Tmp_MAP[0][0];
	MAP[35] = Tmp_MAP[1][0];
	MAP[34] = Tmp_MAP[2][0];
}

void Left_Front_Rotation() { // 왼쪽 면 시계 방향으로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[4];
	int tmp3 = MAP[7];

	MAP[1] = MAP[10];
	MAP[4] = MAP[13];
	MAP[7] = MAP[16];

	MAP[10] = MAP[19];
	MAP[13] = MAP[22];
	MAP[16] = MAP[25];

	MAP[19] = MAP[54];
	MAP[22] = MAP[51];
	MAP[25] = MAP[48];

	MAP[54] = tmp1;
	MAP[51] = tmp2;
	MAP[48] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[30];
	Tmp_MAP[0][1] = MAP[29];
	Tmp_MAP[0][2] = MAP[28];
	Tmp_MAP[1][0] = MAP[33];
	Tmp_MAP[1][1] = MAP[32];
	Tmp_MAP[1][2] = MAP[31];
	Tmp_MAP[2][0] = MAP[36];
	Tmp_MAP[2][1] = MAP[35];
	Tmp_MAP[2][2] = MAP[34];

	MAP[30] = Tmp_MAP[2][0];
	MAP[29] = Tmp_MAP[1][0];
	MAP[28] = Tmp_MAP[0][0];
	MAP[33] = Tmp_MAP[2][1];
	MAP[32] = Tmp_MAP[1][1];
	MAP[31] = Tmp_MAP[0][1];
	MAP[36] = Tmp_MAP[2][2];
	MAP[35] = Tmp_MAP[1][2];
	MAP[34] = Tmp_MAP[0][2];
}

void Right_Back_Rotation() { // 오른쪽 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[3];
	int tmp2 = MAP[6];
	int tmp3 = MAP[9];

	MAP[3] = MAP[12];
	MAP[6] = MAP[15];
	MAP[9] = MAP[18];

	MAP[12] = MAP[21];
	MAP[15] = MAP[24];
	MAP[18] = MAP[27];

	MAP[21] = MAP[52];
	MAP[24] = MAP[49];
	MAP[27] = MAP[46];

	MAP[52] = tmp1;
	MAP[49] = tmp2;
	MAP[46] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[39];
	Tmp_MAP[0][1] = MAP[38];
	Tmp_MAP[0][2] = MAP[37];
	Tmp_MAP[1][0] = MAP[42];
	Tmp_MAP[1][1] = MAP[41];
	Tmp_MAP[1][2] = MAP[40];
	Tmp_MAP[2][0] = MAP[45];
	Tmp_MAP[2][1] = MAP[44];
	Tmp_MAP[2][2] = MAP[43];

	MAP[39] = Tmp_MAP[0][2];
	MAP[38] = Tmp_MAP[1][2];
	MAP[37] = Tmp_MAP[2][2];
	MAP[42] = Tmp_MAP[0][1];
	MAP[41] = Tmp_MAP[1][1];
	MAP[40] = Tmp_MAP[2][1];
	MAP[45] = Tmp_MAP[0][0];
	MAP[44] = Tmp_MAP[1][0];
	MAP[43] = Tmp_MAP[2][0];
}

void Right_Front_Rotation() { // 오른쪽 면 시계 방향으로 돌리기
	int tmp1 = MAP[3];
	int tmp2 = MAP[6];
	int tmp3 = MAP[9];

	MAP[3] = MAP[52];
	MAP[6] = MAP[49];
	MAP[9] = MAP[46];

	MAP[52] = MAP[21];
	MAP[49] = MAP[24];
	MAP[46] = MAP[27];

	MAP[21] = MAP[12];
	MAP[24] = MAP[15];
	MAP[27] = MAP[18];

	MAP[12] = tmp1;
	MAP[15] = tmp2;
	MAP[18] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[39];
	Tmp_MAP[0][1] = MAP[38];
	Tmp_MAP[0][2] = MAP[37];
	Tmp_MAP[1][0] = MAP[42];
	Tmp_MAP[1][1] = MAP[41];
	Tmp_MAP[1][2] = MAP[40];
	Tmp_MAP[2][0] = MAP[45];
	Tmp_MAP[2][1] = MAP[44];
	Tmp_MAP[2][2] = MAP[43];

	MAP[39] = Tmp_MAP[2][0];
	MAP[38] = Tmp_MAP[1][0];
	MAP[37] = Tmp_MAP[0][0];
	MAP[42] = Tmp_MAP[2][1];
	MAP[41] = Tmp_MAP[1][1];
	MAP[40] = Tmp_MAP[0][1];
	MAP[45] = Tmp_MAP[2][2];
	MAP[44] = Tmp_MAP[1][2];
	MAP[43] = Tmp_MAP[0][2];
}

void Front_Counter_Clock_Rotation() { // 앞 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[2];
	int tmp3 = MAP[3];

	MAP[1] = MAP[39];
	MAP[2] = MAP[42];
	MAP[3] = MAP[45];

	MAP[39] = MAP[27];
	MAP[42] = MAP[26];
	MAP[45] = MAP[25];

	MAP[27] = MAP[34];
	MAP[26] = MAP[31];
	MAP[25] = MAP[28];

	MAP[34] = tmp1;
	MAP[31] = tmp2;
	MAP[28] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[48];
	Tmp_MAP[0][1] = MAP[47];
	Tmp_MAP[0][2] = MAP[46];
	Tmp_MAP[1][0] = MAP[51];
	Tmp_MAP[1][1] = MAP[50];
	Tmp_MAP[1][2] = MAP[49];
	Tmp_MAP[2][0] = MAP[54];
	Tmp_MAP[2][1] = MAP[53];
	Tmp_MAP[2][2] = MAP[52];

	MAP[48] = Tmp_MAP[0][2];
	MAP[47] = Tmp_MAP[1][2];
	MAP[46] = Tmp_MAP[2][2];
	MAP[51] = Tmp_MAP[0][1];
	MAP[50] = Tmp_MAP[1][1];
	MAP[49] = Tmp_MAP[2][1];
	MAP[54] = Tmp_MAP[0][0];
	MAP[53] = Tmp_MAP[1][0];
	MAP[52] = Tmp_MAP[2][0];
}

void Front_Clock_Rotation() { // 앞 면 시계 방향으로 돌리기
	int tmp1 = MAP[1];
	int tmp2 = MAP[2];
	int tmp3 = MAP[3];

	MAP[1] = MAP[34];
	MAP[2] = MAP[31];
	MAP[3] = MAP[28];

	MAP[34] = MAP[27];
	MAP[31] = MAP[26];
	MAP[28] = MAP[25];

	MAP[27] = MAP[39];
	MAP[26] = MAP[42];
	MAP[25] = MAP[45];

	MAP[39] = tmp1;
	MAP[42] = tmp2;
	MAP[45] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[48];
	Tmp_MAP[0][1] = MAP[47];
	Tmp_MAP[0][2] = MAP[46];
	Tmp_MAP[1][0] = MAP[51];
	Tmp_MAP[1][1] = MAP[50];
	Tmp_MAP[1][2] = MAP[49];
	Tmp_MAP[2][0] = MAP[54];
	Tmp_MAP[2][1] = MAP[53];
	Tmp_MAP[2][2] = MAP[52];

	MAP[48] = Tmp_MAP[2][0];
	MAP[47] = Tmp_MAP[1][0];
	MAP[46] = Tmp_MAP[0][0];
	MAP[51] = Tmp_MAP[2][1];
	MAP[50] = Tmp_MAP[1][1];
	MAP[49] = Tmp_MAP[0][1];
	MAP[54] = Tmp_MAP[2][2];
	MAP[53] = Tmp_MAP[1][2];
	MAP[52] = Tmp_MAP[0][2];
}

void Back_Counter_Clock_Rotation() { // 뒷 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[9];
	int tmp2 = MAP[8];
	int tmp3 = MAP[7];

	MAP[9] = MAP[30];
	MAP[8] = MAP[33];
	MAP[7] = MAP[36];

	MAP[30] = MAP[19];
	MAP[33] = MAP[20];
	MAP[36] = MAP[21];

	MAP[19] = MAP[43];
	MAP[20] = MAP[40];
	MAP[21] = MAP[37];

	MAP[43] = tmp1;
	MAP[40] = tmp2;
	MAP[37] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[12];
	Tmp_MAP[0][1] = MAP[11];
	Tmp_MAP[0][2] = MAP[10];
	Tmp_MAP[1][0] = MAP[15];
	Tmp_MAP[1][1] = MAP[14];
	Tmp_MAP[1][2] = MAP[13];
	Tmp_MAP[2][0] = MAP[18];
	Tmp_MAP[2][1] = MAP[17];
	Tmp_MAP[2][2] = MAP[16];

	MAP[12] = Tmp_MAP[0][2];
	MAP[11] = Tmp_MAP[1][2];
	MAP[10] = Tmp_MAP[2][2];
	MAP[15] = Tmp_MAP[0][1];
	MAP[14] = Tmp_MAP[1][1];
	MAP[13] = Tmp_MAP[2][1];
	MAP[18] = Tmp_MAP[0][0];
	MAP[17] = Tmp_MAP[1][0];
	MAP[16] = Tmp_MAP[2][0];
}

void Back_Clock_Rotation() { // 뒷 면 시계 방향으로 돌리기
	int tmp1 = MAP[9];
	int tmp2 = MAP[8];
	int tmp3 = MAP[7];

	MAP[9] = MAP[43];
	MAP[8] = MAP[40];
	MAP[7] = MAP[37];

	MAP[43] = MAP[19];
	MAP[40] = MAP[20];
	MAP[37] = MAP[21];

	MAP[19] = MAP[30];
	MAP[20] = MAP[33];
	MAP[21] = MAP[36];

	MAP[30] = tmp1;
	MAP[33] = tmp2;
	MAP[36] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[12];
	Tmp_MAP[0][1] = MAP[11];
	Tmp_MAP[0][2] = MAP[10];
	Tmp_MAP[1][0] = MAP[15];
	Tmp_MAP[1][1] = MAP[14];
	Tmp_MAP[1][2] = MAP[13];
	Tmp_MAP[2][0] = MAP[18];
	Tmp_MAP[2][1] = MAP[17];
	Tmp_MAP[2][2] = MAP[16];

	MAP[12] = Tmp_MAP[2][0];
	MAP[11] = Tmp_MAP[1][0];
	MAP[10] = Tmp_MAP[0][0];
	MAP[15] = Tmp_MAP[2][1];
	MAP[14] = Tmp_MAP[1][1];
	MAP[13] = Tmp_MAP[0][1];
	MAP[18] = Tmp_MAP[2][2];
	MAP[17] = Tmp_MAP[1][2];
	MAP[16] = Tmp_MAP[0][2];
}

void Up_Counter_Clock_Rotation() { // 윗 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[10];
	int tmp2 = MAP[11];
	int tmp3 = MAP[12];

	MAP[10] = MAP[37];
	MAP[11] = MAP[38];
	MAP[12] = MAP[39];

	MAP[37] = MAP[46];
	MAP[38] = MAP[47];
	MAP[39] = MAP[48];

	MAP[46] = MAP[28];
	MAP[47] = MAP[29];
	MAP[48] = MAP[30];

	MAP[28] = tmp1;
	MAP[29] = tmp2;
	MAP[30] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[7];
	Tmp_MAP[0][1] = MAP[8];
	Tmp_MAP[0][2] = MAP[9];
	Tmp_MAP[1][0] = MAP[4];
	Tmp_MAP[1][1] = MAP[5];
	Tmp_MAP[1][2] = MAP[6];
	Tmp_MAP[2][0] = MAP[1];
	Tmp_MAP[2][1] = MAP[2];
	Tmp_MAP[2][2] = MAP[3];

	MAP[7] = Tmp_MAP[0][2];
	MAP[8] = Tmp_MAP[1][2];
	MAP[9] = Tmp_MAP[2][2];
	MAP[4] = Tmp_MAP[0][1];
	MAP[5] = Tmp_MAP[1][1];
	MAP[6] = Tmp_MAP[2][1];
	MAP[1] = Tmp_MAP[0][0];
	MAP[2] = Tmp_MAP[1][0];
	MAP[3] = Tmp_MAP[2][0];
}

void Up_Clock_Rotation() { // 윗 면 시계 방향으로 돌리기
	int tmp1 = MAP[10];
	int tmp2 = MAP[11];
	int tmp3 = MAP[12];

	MAP[10] = MAP[28];
	MAP[11] = MAP[29];
	MAP[12] = MAP[30];

	MAP[28] = MAP[46];
	MAP[29] = MAP[47];
	MAP[30] = MAP[48];

	MAP[46] = MAP[37];
	MAP[47] = MAP[38];
	MAP[48] = MAP[39];

	MAP[37] = tmp1;
	MAP[38] = tmp2;
	MAP[39] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[7];
	Tmp_MAP[0][1] = MAP[8];
	Tmp_MAP[0][2] = MAP[9];
	Tmp_MAP[1][0] = MAP[4];
	Tmp_MAP[1][1] = MAP[5];
	Tmp_MAP[1][2] = MAP[6];
	Tmp_MAP[2][0] = MAP[1];
	Tmp_MAP[2][1] = MAP[2];
	Tmp_MAP[2][2] = MAP[3];

	MAP[7] = Tmp_MAP[2][0];
	MAP[8] = Tmp_MAP[1][0];
	MAP[9] = Tmp_MAP[0][0];
	MAP[4] = Tmp_MAP[2][1];
	MAP[5] = Tmp_MAP[1][1];
	MAP[6] = Tmp_MAP[0][1];
	MAP[1] = Tmp_MAP[2][2];
	MAP[2] = Tmp_MAP[1][2];
	MAP[3] = Tmp_MAP[0][2];
}

void Down_Counter_Clock_Rotation() { // 아랫 면 반 시계 방향으로 돌리기
	int tmp1 = MAP[16];
	int tmp2 = MAP[17];
	int tmp3 = MAP[18];

	MAP[16] = MAP[34];
	MAP[17] = MAP[35];
	MAP[18] = MAP[36];

	MAP[34] = MAP[52];
	MAP[35] = MAP[53];
	MAP[36] = MAP[54];

	MAP[52] = MAP[43];
	MAP[53] = MAP[44];
	MAP[54] = MAP[45];

	MAP[43] = tmp1;
	MAP[44] = tmp2;
	MAP[45] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[21];
	Tmp_MAP[0][1] = MAP[20];
	Tmp_MAP[0][2] = MAP[19];
	Tmp_MAP[1][0] = MAP[24];
	Tmp_MAP[1][1] = MAP[23];
	Tmp_MAP[1][2] = MAP[22];
	Tmp_MAP[2][0] = MAP[27];
	Tmp_MAP[2][1] = MAP[26];
	Tmp_MAP[2][2] = MAP[25];

	MAP[21] = Tmp_MAP[0][2];
	MAP[20] = Tmp_MAP[1][2];
	MAP[19] = Tmp_MAP[2][2];
	MAP[24] = Tmp_MAP[0][1];
	MAP[23] = Tmp_MAP[1][1];
	MAP[22] = Tmp_MAP[2][1];
	MAP[27] = Tmp_MAP[0][0];
	MAP[26] = Tmp_MAP[1][0];
	MAP[25] = Tmp_MAP[2][0];
}

void Down_Clock_Rotation() { // 아랫 면 시계 방향으로 돌리기
	int tmp1 = MAP[16];
	int tmp2 = MAP[17];
	int tmp3 = MAP[18];

	MAP[16] = MAP[43];
	MAP[17] = MAP[44];
	MAP[18] = MAP[45];

	MAP[43] = MAP[52];
	MAP[44] = MAP[53];
	MAP[45] = MAP[54];

	MAP[52] = MAP[34];
	MAP[53] = MAP[35];
	MAP[54] = MAP[36];

	MAP[34] = tmp1;
	MAP[35] = tmp2;
	MAP[36] = tmp3;

	int Tmp_MAP[3][3];
	Tmp_MAP[0][0] = MAP[21];
	Tmp_MAP[0][1] = MAP[20];
	Tmp_MAP[0][2] = MAP[19];
	Tmp_MAP[1][0] = MAP[24];
	Tmp_MAP[1][1] = MAP[23];
	Tmp_MAP[1][2] = MAP[22];
	Tmp_MAP[2][0] = MAP[27];
	Tmp_MAP[2][1] = MAP[26];
	Tmp_MAP[2][2] = MAP[25];

	MAP[21] = Tmp_MAP[2][0];
	MAP[20] = Tmp_MAP[1][0];
	MAP[19] = Tmp_MAP[0][0];
	MAP[24] = Tmp_MAP[2][1];
	MAP[23] = Tmp_MAP[1][1];
	MAP[22] = Tmp_MAP[0][1];
	MAP[27] = Tmp_MAP[2][2];
	MAP[26] = Tmp_MAP[1][2];
	MAP[25] = Tmp_MAP[0][2];
}

int main() {
	FIRST
	cin >> T;
	while (T--) {
		init();
		cin >> N;
		for (int i = 0; i < N; i++) {
			string S;
			cin >> S;
			if (S == "U-") {
				Up_Counter_Clock_Rotation();
			}
			else if (S == "U+") {
				Up_Clock_Rotation();
			}
			else if (S == "D-") {
				Down_Counter_Clock_Rotation();
			}
			else if (S == "D+") {
				Down_Clock_Rotation();
			}
			else if (S == "F-") {
				Front_Counter_Clock_Rotation();
			}
			else if (S == "F+") {
				Front_Clock_Rotation();
			}
			else if (S == "B-") {
				Back_Counter_Clock_Rotation();
			}
			else if (S == "B+") {
				Back_Clock_Rotation();
			}
			else if (S == "L-") {
				Left_Back_Rotation();
			}
			else if (S == "L+") {
				Left_Front_Rotation();
			}
			else if (S == "R-") {
				Right_Back_Rotation();
			}
			else if (S == "R+") {
				Right_Front_Rotation();
			}
		}
		cout << MAP[7] << MAP[8] << MAP[9] << "\n";
		cout << MAP[4] << MAP[5] << MAP[6] << "\n";
		cout << MAP[1] << MAP[2] << MAP[3] << "\n";
	};

	return 0;
}