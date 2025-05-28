#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 2e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<i64> a(n + 2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = inf;
    while (q--) {
        i64 k; cin >> k;
        i64 lo = 1;
        i64 hi = 2e18;
        auto f = [&] (i64 x) -> i64 {
            int ind = lower_bound(a.begin(), a.end(), x) - a.begin();
            return x - ind;
        };
        while (lo < hi) {
            i64 mid = (lo + hi) / 2;
            if (f(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        cout << max(1LL, lo - 1) << "\n";
    }
    return 0;
}
