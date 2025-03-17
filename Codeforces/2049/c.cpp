#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> ans(n, 0);
    x--, y--;
    for (int i = 0; i < n; ++i) {
        ans[(i + x) % n] = i % 2;
    }
    if (n & 1 || (x - y) % 2 == 0) ans[x] = 2;
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];  
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


