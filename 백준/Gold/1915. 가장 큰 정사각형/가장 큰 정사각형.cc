#include<iostream>
#include<string>
 
#define endl "\n"
#define MAX 1010
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        string Inp; cin >> Inp;
        for (int j = 0; j < Inp.length(); j++)
        {
            MAP[i][j + 1] = Inp[j] - '0';
        }
    }
}
 
void Solution()
{
    int Max_Len = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] != 0)
            {
                MAP[i][j] = Min(MAP[i - 1][j - 1], Min(MAP[i - 1][j], MAP[i][j - 1])) + 1;
                if (Max_Len < MAP[i][j]) Max_Len = MAP[i][j];
            }
        }
    }
 
    cout << Max_Len * Max_Len << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}


// 출처: https://yabmoons.tistory.com/158 [얍문's Coding World..]