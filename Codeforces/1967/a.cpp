#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        i64 k; cin >> k;
        vector<i64> a(n);
        for (auto &e : a) cin >> e;
        i64 lo = 1;
        i64 hi = 1e12;
        auto f = [&] (i64 x) -> i64 {
            i64 res = 0;
            for (int i = 0; i < n; ++i) {
                res += max(0LL, x - a[i]);
            }
            return res;
        };
        while (lo < hi) {
            i64 mid = (lo + hi + 1) / 2;
            if (f(mid) <= k) lo = mid;
            else hi = mid - 1;
        }
        i64 remain = k - f(lo);
        i64 cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (a[i] <= lo);
        }
        cnt -= remain;
        i64 ans = 1LL * n * lo - cnt + 1;
        cout << ans << "\n";
    }
    return 0;
}


