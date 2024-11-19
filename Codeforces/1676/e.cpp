#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> prefix(n + 1, 0);
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; ++i) {
        prefix[i + 1] = prefix[i] + a[i];
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (prefix[mid] >= x) hi = mid;
            else lo = mid + 1;
        }
        if (prefix[lo] >= x) cout << lo << "\n";
        else cout << -1 << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

