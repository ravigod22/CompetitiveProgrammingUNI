#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<bool> is_zero(n + 1, 0);
    int l = 0, ans = 0;
    set<int> aux;
    while (l < n) {
        if (is_zero[a[l]]) a[l] = 0;
        if (a[l]) aux.emplace(a[l]);
        int r = l + 1;
        while (r < n && (is_zero[a[r - 1]] ? 0 : a[r - 1]) <= (is_zero[a[r]] ? 0 : a[r])) {
            if (is_zero[a[r - 1]]) a[r - 1] = 0;
            if (is_zero[a[r]]) a[r] = 0;
            if (a[r]) aux.emplace(a[r]);
            r++;
        }
        if (r == n) break;
        for (int e : aux) is_zero[e] = 1;
        ans += (int)aux.size();
        aux.clear();
        l = r;
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


