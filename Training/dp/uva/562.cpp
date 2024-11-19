#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int test = 0; test < n; ++test) {
        int m; cin >> m;
        vector<int> c(m);
        for (int& e : c) cin >> e;
        int sum = accumulate(c.begin(), c.end(), 0);
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            vector<int> dp_tmp = dp;
            for (int j = 0; j <= sum; ++j) {
                if (c[i] <= j) dp_tmp[j] |= dp[j - c[i]];
            }
            swap(dp, dp_tmp);
        }
        int ans = 2e9;
        for (int i = 0; i <= sum; ++i) {
            int tmp = sum - i;
            if (dp[i]) ans = min(ans, abs(tmp - i));  
        }
        cout << ans << "\n"; 
    }
    return 0;
}
