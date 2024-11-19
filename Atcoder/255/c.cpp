#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        long long x, a, n;
        long long d;
        cin >> x >> a >> d >> n;
        long long lo, hi;
        long long ans = 0;
        if (d >= 0) {
            lo = 0;
            hi = n - 1;
            while (lo < hi) {
                long long mid = (lo + hi + 1) / 2;
                if ((a + (d * mid)) <= x) lo = mid;
                else hi = mid - 1;
            }
            if (lo != 0 && lo != n - 1) {
                ans = min(abs(a + (1ll * d * lo) - x), abs(a + (1ll * d * (lo + 1)) - x));
            }
            else ans = abs(a + (1ll * d * lo) - x);
        }
        else {
            lo = 0;
            hi = n - 1;
            while (lo < hi) {
                long long mid = (lo + hi) / 2;
                if ((a + (d * mid)) <= x) hi = mid;
                else lo = mid + 1;
            }
            if (lo != 0 && lo != n - 1) {
                ans = min(abs(a + (1ll * d * lo) - x), abs(a + (1ll * d * (lo - 1)) - x));
            }
            else ans = abs(a + (1ll * d * lo) - x);
        }
        cout << ans << "\n";
    }
    return 0;
}
