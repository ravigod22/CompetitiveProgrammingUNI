#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> op(n);
    for (auto& e : op) cin >> e.first >> e.second;
    int x = op.front().first, y = op.front().second;
    int sum = 4 * m * n;
    for (int i = 1; i < n; ++i) {
        sum -= 2 * (m - op[i].first) + 2 * (m - op[i].second);
    }
    cout << sum << "\n";
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


