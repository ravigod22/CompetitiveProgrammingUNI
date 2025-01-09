#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    i64 x, y; cin >> x >> y;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    i64 acc = accumulate(a.begin(), a.end(), 0LL);
    sort(a.begin(), a.end());
    i64 cnt = 0;
    for (int i = 1; i < n; ++i) {
        i64 t1 = acc - y - a[i];
        i64 t2 = acc - x - a[i];
        int it1 = lower_bound(a.begin(), a.begin() + i, t1) - a.begin();
        int it2 = upper_bound(a.begin(), a.begin() + i, t2) - a.begin();
        it2--;
        cnt += max(0LL, 0LL + it2 - it1 + 1);
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



