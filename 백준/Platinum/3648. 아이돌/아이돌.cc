#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<vector<int>> v, rev;
stack<int> s;
bool visited[2003];
int scc[2003], idx, n, m;

inline int T(int x) { return x << 1; }
inline int F(int x) { return x << 1 | 1; }
inline int NOT(int x) { return x ^ 1; }

void dfs(int cur) {
    visited[cur] = true;
    for (auto nxt : v[cur]) {
        if (!visited[nxt]) dfs(nxt);
    }
    s.push(cur);
}

void rev_dfs(int cur) {
    visited[cur] = true;
    scc[cur] = idx;
    for (auto nxt : rev[cur]) {
        if (!visited[nxt]) rev_dfs(nxt);
    }
}

void SCC() {
    memset(visited, 0, sizeof visited);    
    for (int i = 2; i <= 2 * n + 1; i++) {
        if (!visited[i]) dfs(i);
    }

    memset(scc, 0, sizeof scc);
    memset(visited, 0, sizeof visited);
    idx = 1;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (!visited[cur]) {
            rev_dfs(cur);
            idx++;
        }
    }
}


int main() {
    while (scanf("%d %d", &n, &m) > 0) {
        v.clear(); v.resize((n << 1) + 2);
        rev.clear(); rev.resize((n << 1) + 2);
        while (m--) {
            int a, b; scanf("%d %d", &a, &b);
            a = a > 0 ? T(a) : F(-a);
            b = b > 0 ? T(b) : F(-b);
            v[NOT(a)].push_back(b);
            v[NOT(b)].push_back(a);
            rev[b].push_back(NOT(a));
            rev[a].push_back(NOT(b));        
        }

        SCC();

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (scc[T(i)] == scc[F(i)]) flag = true;
        }
        if (scc[T(1)] > scc[F(1)] && !flag) printf("yes\n");
        else printf("no\n");
    }
}