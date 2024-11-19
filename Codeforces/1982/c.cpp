#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, l , r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<long long> prefix(n + 1, 0);
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + 0ll + a[i];
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1];
            int lo = 0; 
            int hi = i - 1;
            auto check = [&] (int mid) -> bool {
                return prefix[i] - prefix[mid] >= 1ll * l;
            };
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (check(mid)) lo = mid;
                else hi = mid - 1;
            }
            if (check(lo) && prefix[i] - prefix[lo] <= r) {
                dp[i] = max(dp[i], dp[lo] + 1);
            } 
        }
        cout << dp[n] << "\n";
    }
    return 0;
}

