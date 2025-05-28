#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 10;
string s, t;
int dp[maxn][maxn];
string ans;

int f(int i, int j) {
    if (i == s.size() || j == t.size()) return 0;
    if (~dp[i][j]) return dp[i][j];
    int& x = dp[i][j];
    x = max(f(i + 1, j), f(i, j + 1));
    if (s[i] == t[j]) x = max(x, 1 + f(i + 1, j + 1));
    return x;
}

void build(int i, int j) {
    if (i == s.size() || j == t.size()) return;
    if (f(i, j) == f(i + 1, j)) build(i + 1, j);
    else if (f(i, j) == f(i, j + 1)) build(i, j + 1);
    else if (s[i] == t[j]) {
        ans += s[i];
        build(i + 1, j + 1);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    build(0, 0);
    cout << ans << "\n";
    return 0;
}
