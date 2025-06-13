#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    map<int, int> d, ad;
    map<int, int> ejex, ejey;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ejex[x]++;
        ejey[y]++;
        d[x + y]++;
        ad[x - y]++;
    }
    i64 res = 0;
    for (auto [_, cnt] : ejex) res += 1LL * cnt * (cnt - 1);
    for (auto [_, cnt] : ejey) res += 1LL * cnt * (cnt - 1);
    for (auto [_, cnt] : d) res += 1LL * cnt * (cnt - 1);
    for (auto [_, cnt] : ad) res += 1LL * cnt * (cnt - 1);
    cout << res << "\n";
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


