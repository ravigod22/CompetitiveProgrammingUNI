#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

long long binpow(long long a, long long b) {
    long long result = 1;
    while (b) {
        if (b & 1) result = result * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return result;
}

void solve() {
    int n; cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long dp[n + 1][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(a[i] + dp[i - 1][0], a[i] + dp[i - 1][1]);
        dp[i][1] = max(abs(a[i] + dp[i - 1][0]), abs(a[i] + dp[i - 1][1]));
        cout << "i -> " << i << "\n";
        cout << "dp op1: " << dp[i][0] << "\n";
        cout << "dp op2: " << dp[i][1] << "\n";
    }
    long long ans = max(dp[n][1], dp[n][0]);
    /*
    long long cnt[n + 1][2];
    memset(cnt, 0, sizeof(cnt));
    cnt[1][0] = cnt[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] + dp[i - 1][0] == dp[i][0]) cnt[i][0] = (cnt[i][0] + cnt[i - 1][0]) % mod;
        if (a[i] + dp[i - 1][0] == dp[i][1]) cnt[i][1] = (cnt[i][1] + cnt[i - 1][0]) % mod;
        if (a[i] + dp[i - 1][1] == dp[i][0]) cnt[i][0] = (cnt[i][0] + cnt[i - 1][1]) % mod;
        if (a[i] + dp[i - 1][1] == dp[i][1]) cnt[i][1] = (cnt[i][1] + cnt[i - 1][1]) % mod;
        if (abs(a[i] + dp[i - 1][0]) == dp[i][0]) cnt[i][0] = (cnt[i][0] + cnt[i - 1][0]) % mod;
        if (abs(a[i] + dp[i - 1][0]) == dp[i][1]) cnt[i][1] = (cnt[i][1] + cnt[i - 1][0]) % mod; 
        if (abs(a[i] + dp[i - 1][1]) == dp[i][0]) cnt[i][0] = (cnt[i][0] + cnt[i - 1][1]) % mod; 
        if (abs(a[i] + dp[i - 1][1]) == dp[i][1]) cnt[i][1] = (cnt[i][1] + cnt[i - 1][1]) % mod; 
        cnt[i][0] = ((a[i] + dp[i - 1][0] == dp[i][0] ? cnt[i - 1][0] : 0) + (a[i] + dp[i - 1][1] == dp[i][0] ? cnt[i - 1][1] : 0)) % mod;
        cnt[i][1] = ((abs(a[i] + dp[i - 1][0]) == dp[i][1] ? cnt[i - 1][0] : 0) + (abs(a[i] + dp[i - 1][1]) == dp[i][1] ? cnt[i - 1][1] : 0)) % mod;
        cout << "i -> " << i << "\n";
        cout << "opcion 1: " << cnt[i][0] << "\n";
        cout << "opcion 2: " << cnt[i][1] << "\n";
    }
    long long cnt_total = ((ans == dp[n][1] ? cnt[n][1] : 0) + (ans == dp[n][0] ? cnt[n][0] : 0)) % mod;
    cout << cnt_total << "\n";
    */
    long long cnt_pos = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= 0) cnt_pos++;
    }
    if (cnt_pos == 0) cout << "1\n";
    else {
        cnt_pos += (a[0] < 0 ? 1 : 0);
        long long neg = n - cnt_pos;
        cout << binpow(2, cnt_pos) * ((binpow(2, neg) - 1 + mod) % mod) % mod << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



