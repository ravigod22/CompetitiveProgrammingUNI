#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
int dp[2][64][64][2];
int k;
i64 n;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int cnt(int pos, int remain, bool same) {
    if (pos == -1) return (remain == 0);
    if (!remain) return 1;
    if (~dp[0][pos][remain][same]) return dp[0][pos][remain][same];
    int &ans = dp[0][pos][remain][same] = 0;
    if (same) {
        int bit = (n >> pos) & 1;
        for (int i = 0; i <= bit; ++i) {
            ans = add(ans, cnt(pos - 1, remain - i, i == bit));
        }
    }
    else {
        ans = add(ans, cnt(pos - 1, remain - 1, 0));
        ans = add(ans, cnt(pos - 1, remain, 0));
    }
    return ans;
}
int f(int pos, int remain, bool same) {
    if (pos == -1) return 0;
    if (remain == 0) return 0;
    if (~dp[1][pos][remain][same]) return dp[1][pos][remain][same];
    int &res = dp[1][pos][remain][same] = 0;
    i64 escalar = (1LL << pos) % mod;
    if (same) {
        int bit = (n >> pos) & 1;
        for (int i = 0; i <= bit; ++i) {
            int tmp = mul(i, cnt(pos - 1, remain - i, i == bit));
            res = add(res, mul(escalar, tmp));
            res = add(res, f(pos - 1, remain - i, i == bit));
        }
    }
    else {
        res = add(res, mul(escalar, cnt(pos - 1, remain - 1, 0)));
        res = add(res, f(pos - 1, remain - 1, 0));
        res = add(res, f(pos - 1, remain, 0));
    }
    return res;
}

void solve() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << f(61, k, 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




