#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

vector<int> get_divisor(int x) {
    vector<int> ans;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ans.emplace_back(i);
            if (i != (x / i)) {
                ans.emplace_back(x / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y; cin >> x >> y;
    if (y % x) {
        cout << 0 << "\n";
        return 0;
    }
    y /= x;
    vector<int> div = get_divisor(y);
    map<int, int> dp;
    dp[1] = 1;
    // f(t) = 2 ^ (t - 1) - /sum f(t / x)
    // where x is a divisor of t
    for (int i = 1; i < div.size(); ++i) {
        dp[div[i]] = binpow(2, div[i] - 1);
        for (int j = 0; j < i; ++j) {
            if (div[i] % div[j] == 0) {
                dp[div[i]] = (dp[div[i]] - dp[div[j]] + mod) % mod;  
            }
        }
    }
    cout << dp[y] << "\n";
    return 0;
}
