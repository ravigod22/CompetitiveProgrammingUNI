#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<pair<int, int>> queries(n);
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        queries[i] = {x, i};
    }
    reverse(a.begin(), a.end());
    sort(queries.begin(), queries.end());
    vector<int> ans(n, 0);
    int p = 0, t = 0;
    int xoraccumulate = 0;
    int cnt = 0;
    while (q--) {
        int cur = queries[t].first;
        while (p < n && (cur ^ xoraccumulate) >= a[p]) {
            xoraccumulate ^= a[p];
            cnt++;
            p++;
        }
        ans[queries[t].second] = cnt;
        t++;
    }
    for (int e : ans) cout << e << " ";
    cout << "\n";
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


