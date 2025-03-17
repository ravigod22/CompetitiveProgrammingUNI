#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m; cin >> n >> m;
    vector<int> r(n), c(n);
    for (int &e : c) cin >> e;
    for (int &e : r) cin >> e;
    map<int, pair<i64, i64>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = c[i] - r[i]; j <= c[i] + r[i]; ++j) {
            i64 aux = 1LL * (j - c[i]) * (j - c[i]);
            i64 tmp = 1LL * r[i] * r[i] - aux;
            i64 L = -sqrtl(tmp), R = sqrtl(tmp);
            if (!mp.count(j)) {
                mp[j] = {L, R};
            }
            else {
                i64 Lprime = min(L, mp[j].first);
                i64 Rprime = max(R, mp[j].second);
                mp[j] = {Lprime, Rprime};
            }
        }
    }
    i64 ans = 0;
    for (auto [k, v] : mp) {
        ans += v.second - v.first + 1;
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

