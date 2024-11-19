#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int x, sum = 0;
        int dp[201];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        while (cin >> x) {
            sum += x;
            for (int i = 200; i >= 0; --i) {
                if (i >= x) dp[i] |= dp[i - x];
            }
            if (cin.peek() == '\n' || cin.peek() == EOF) break;
        }
        if (sum & 1) cout << "NO\n";
        else cout << (dp[sum / 2] ? "YES\n" : "NO\n");
        
    }
    return 0;
}
