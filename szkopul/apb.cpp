#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    string s; cin >> s;
    const int n = s.size();
    vector<i64> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        int onedigit = s[i] - '0';
        dp[i + 1] += (dp[i] * 1LL * (onedigit + 1));
        if (i) {
            int twodigit = 10 * (s[i - 1] - '0') + s[i] - '0';
            if (twodigit < 10) continue;
            int num = 18 - twodigit + 1;
            dp[i + 1] += (dp[i - 1] * 1LL * num);
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
