#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<i64> suffix(n + 2, 0);
    vector<i64> prefix(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suffix[i] = suffix[i + 1] + (a[i] < 0 ? -a[i] : 0);
    }
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + (a[i] > 0 ? a[i] : 0);
    }
    i64 ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = max(ans, prefix[i] + suffix[i]);
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


