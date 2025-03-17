#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> p(n);
    for (int& e : p) cin >> e;
    set<int> s;
    for (int i = 0; i < k; ++i) s.emplace(p[i]);
    int ans = 0;
    for (int i = 1; i <= k; ++i) {
        if (s.count(i)) continue;
        ans++;
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


