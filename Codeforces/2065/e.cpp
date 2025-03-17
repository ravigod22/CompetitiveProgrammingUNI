#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        if (abs(n - m) > k or max(n, m) < k) {
            cout << -1 << "\n";
            continue;
        }
        if (k == 1) {
            if (n > m) {
                for (int i = 0; i < n + m; ++i) {
                    if (i & 1) cout << 1;
                    else cout << 0;
                }
            }
            else {
                for (int i = 0; i < n + m; ++i) {
                    if (i & 1) cout << 0;
                    else cout << 1;
                }
            }
            cout << "\n";
            continue;
        }
        if (n > m) {
            string ans(k, '0');
            n -= k;
            int tmp = 1;
            while (n > 0 || m > 0) {
                if (tmp) {
                    for (int i = 0; i < min(k - 1, m); ++i) ans += '1';
                    m -= min(m, k - 1);
                }
                else {
                    for (int i = 0; i < min(n, k - 1); ++i) ans += '0';
                    n -= min(n, k - 1);
                }
                tmp ^= 1;
            }
            cout << ans << "\n";
        }
        else {
            string ans(k, '1');
            m -= k;
            int tmp = 1;
            while (n > 0 || m > 0) {
                if (tmp) {
                    for (int i = 0; i < min(n, k - 1); ++i) ans += '0';
                    n -= min(n, k - 1);
                }
                else {
                    for (int i = 0; i < min(m, k - 1); ++i) ans += '1';
                    m -= min(m, k - 1);
                }
                tmp ^= 1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}




