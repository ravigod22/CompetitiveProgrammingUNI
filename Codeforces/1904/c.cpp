#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<i64> a(n);
        for (auto& e : a) cin >> e;
        sort(a.begin(), a.end());
        i64 ans = *min_element(a.begin(), a.end());
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                i64 target = abs(a[i] - a[j]);
                ans = min(ans, target);
                if (k == 2) {
                    int it = lower_bound(a.begin(), a.end(), target) - a.begin();
                    ans = min(ans, a[it] - target);
                    if (it || it == n) ans = min(ans, target - a[it - 1]);
                }
            }
        }
        if (k >= 3) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}

