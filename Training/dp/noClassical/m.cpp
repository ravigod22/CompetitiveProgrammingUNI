#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int n, m;
int a[maxn][maxn];
int dp[maxn][maxn];

int add(int a, int b) {
    return (a + b) % mod;
}

int f(int i, int j) {
    if (i >= n || j >= m) return 0;
    if (i + 1 == n && j + 1 == m) return 1;
    if (~dp[i][j]) return dp[i][j];
    int &res = dp[i][j] = 0;
    res = add(res, f(i + a[i][j], j));
    res = add(res, f(i, j + a[i][j]));
    return res;
}


int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    cout << f(0, 0) << "\n";
    return 0;
}
