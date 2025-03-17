#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int & e : a) cin >> e;
        if (k == n) {
            int ans = 1;
            for (int i = 1; i < n; i += 2) {
                if (ans == a[i]) ans++;
                else break;
            }
            cout << ans << "\n";
            continue;
        }
        int res = 2;
        for (int i = 1; i <= n - k + 1; ++i) {
            if (a[i] != 1) {
                res = 1;
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
