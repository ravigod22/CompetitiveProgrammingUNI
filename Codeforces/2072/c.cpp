#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, x; cin >> n >> x;
    int lim = 0;
    for (int i = 0; i < 30; ++i) {
        if ((x >> i) & 1) lim++;
        else break;
    }
    if (n == 1) {
        cout << x << "\n";
        return;
    }
    if (lim == 0) lim = 1;
    else lim = (1 << lim);
    vector<int> ans;
    int ortotal = 0;
    for (int i = 0; i < min(n - 1, lim); ++i) {
        ortotal |= i;
        ans.emplace_back(i);
    }
    if (ans.size() != n - 1) {
        while (ans.size() < n) ans.emplace_back(x);
    }
    else {
        int last = ans.back() + 1;
        if ((ortotal | last) == x) {
            ans.emplace_back(last);
        }
        else ans.emplace_back(x);
    }
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


