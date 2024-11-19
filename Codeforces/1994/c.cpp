#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + 0ll + a[i];
        vector<long long> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int lo = i;
            int hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] - prefix[i - 1] > 1ll * x) hi = mid;
                else lo = mid + 1;
            }
            if (lo == n + 1) continue;
            if (prefix[lo] - prefix[i - 1] > 1ll * x) dp[lo] += 1 + dp[i - 1];
        }
        long long tmp = accumulate(dp.begin(), dp.end(), 0ll);
        cout << (1ll * n * (n + 1)) / 2 - tmp << "\n";
    }
    return 0;
}
