#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int m, k, a1, ak; cin >> m >> k >> a1 >> ak;
        int lo = 0;
        int hi = m / k;
        auto f = [&] (int x) -> int {
            int res = m - x * k;
            return max(0, res - a1) + max(0, x - ak);
        };
        while (hi - lo > 2) {
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            if (f(m1) < f(m2)) hi = m2;
            else lo = m1;
        }
        int ans = 1e9;
        for (int i = lo; i <= hi; ++i) ans = min(ans, f(i));
        cout << ans << "\n";
    }
    return 0;
}
