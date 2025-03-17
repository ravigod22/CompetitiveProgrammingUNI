#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m; cin >> n >> m;
    vector<int> color(m);
    for (int& e : color) cin >> e;
    for (int& e : color) {
        if (e == n) e--;
    }
    sort(color.begin(), color.end());
    vector<i64> prefix(m, 0);
    for (int i = 0; i < m; ++i) prefix[i] = (i ? prefix[i - 1] : 0) + color[i];
    i64 ans = 0;
    for (int i = 0; i + 1 < m; ++i) {
        int it = lower_bound(color.begin() + i + 1, color.end(), n - color[i]) - color.begin();
        if (it == m) continue;
        int dis = m - it;
        ans += (prefix[m - 1] - prefix[it - 1] + 1LL * (color[i] + 1 - n) * dis);
    }
    cout << 2LL * ans << "\n";
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


