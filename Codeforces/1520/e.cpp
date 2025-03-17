#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

using i64 = long long;
const i64 inf = 1e18;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(n + 1, 0);
    vector<i64> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (s[i] == '*' ? i + 1 : 0);
        cnt[i + 1] = cnt[i] + (s[i] == '*');
    }
    i64 ans = inf;
    for (int i = 1; i <= n; ++i) {
        int nleft = cnt[i - 1];
        int nright = (i == n ? 0 : cnt[n] - cnt[i]);
        i64 sumleft = prefix[i - 1];
        i64 sumright = (i == n ? 0LL : prefix[n] - prefix[i]);
        if (s[i - 1] == '*') {
            i64 tmp1 = 1LL * nleft * i - sumleft - (1LL * nleft * (nleft + 1)) / 2;
            i64 tmp2 = sumright - 1LL * nright * i - (1LL * nright * (nright + 1)) / 2;
            ans = min(ans, tmp1 + tmp2);
        }
        else {
            i64 tmp1L = 1LL * nleft * i - sumleft - (1LL * (nleft - 1) * nleft) / 2;
            i64 tmp1R = sumright - 1LL * nright * i - (1LL * nright * (nright + 1)) / 2;
            i64 tmp2L = 1LL * nleft * i - sumleft - (1LL * nleft * (nleft + 1)) / 2;
            i64 tmp2R = sumright - 1LL * nright * i - (1LL * (nright - 1) * nright) / 2;
            ans = min(ans, tmp1L + tmp1R);
            ans = min(ans, tmp2L + tmp2R);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


