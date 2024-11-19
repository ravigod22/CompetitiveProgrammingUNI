#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e3 + 10;
int dp[maxn][maxn];
string s;

int f(int l, int r) {
    if (l == r) return 1;
    if (l + 1 == r) return (s[l] == s[r]);
    if (~dp[l][r]) return dp[l][r];
    int& ans = dp[l][r] = 0;
    ans += f(l + 1, r);
    ans += f(l, r - 1);
    if (s[l] == s[r]) ans += f(l + 1, r - 1);
    return ans;
}

void solve() {
    cin >> s;
    int q; cin >> q;
    int n = s.size();
    int total = f(0, n - 1);
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << f(l, r) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}
