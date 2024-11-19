#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < k; ++i) {
        int b, c; cin >> b >> c;
        cnt[b] += c;
    }
    sort(cnt.rbegin(), cnt.rend());
    int ans = 0;
    for (int i = 0; i < min(k, n); ++i) {
        ans += cnt[i];
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


