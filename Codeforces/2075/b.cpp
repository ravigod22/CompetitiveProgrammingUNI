#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    i64 ans = 0;
    if (k == 1) {
        ans = 1LL * max(a[0], a[n - 1]);
        int tmp = 0;
        for (int i = 1; i + 1 < n; ++i) {
            tmp = max(tmp, a[i]);
        }
        cout << max(ans + tmp, 0LL + a[0] + a[n - 1]) << "\n";
        return;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i <= k; ++i) ans += a[i];
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


