#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<int> a(n);
        for (auto& e : a) cin >> e;
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            dp[i] = a[i];
            for (int j = 0; j < i; ++j) {
                if (a[j] < a[i]) dp[i] = max(dp[i], a[i] + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
