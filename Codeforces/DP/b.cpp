#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<bool> exist(26, false);
    for (int i = 0; i < k; ++i) {
        char x; cin >> x;
        exist[x - 'a'] = true;
    }
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        char tmp = s[i - 1];
        dp[i] = (exist[tmp - 'a'] ? 1 + dp[i - 1] : 0);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += dp[i];
    cout << ans << "\n";
    return 0;
}
