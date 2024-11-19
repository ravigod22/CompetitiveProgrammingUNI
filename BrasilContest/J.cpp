#include <bits/stdc++.h>
using namespace std;
int N, M;
const int maxn = 1e2 + 5;
const int maxm = 1e3 + 5;
const int inf = 1e9;

int O[maxm], L[maxm];
int dp[maxn][maxm];
bool vis[maxn][maxm];

int f(int pos, int golds) {
    if (pos == M) return (golds == 0 ? 0 : inf);
    if (golds < 0) return inf;
    if (vis[pos][golds]) return dp[pos][golds];
    vis[pos][golds] = true;
    int& ans = dp[pos][golds] = f(pos + 1, golds);
    for (int i = 1; i <= L[pos]; ++i) {
        ans = min(ans, i + f(pos + 1, golds - i * O[pos]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> O[i];
    for (int i = 0; i < M; ++i) cin >> L[i];
    
    cout << (f(0, N) == inf ? -1 : f(0, N)) << "\n";
    return 0;
}
