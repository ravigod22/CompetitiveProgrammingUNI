#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    i64 x; cin >> x;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<i64> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
    i64 ans = 0, total = 1LL * prefix[n] * k;
    for (int i = 1; i <= n; ++i) {
        i64 sum = total - prefix[i - 1];
        if (sum < x) continue;
        i64 L = 0, R = (sum - x) / prefix[n];
        ans += max(0LL, R - L + 1);
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


