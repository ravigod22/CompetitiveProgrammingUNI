#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}
int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<int> dp(n + 1, 1);
    for (int i = 0; i < m; ++i) {
        vector<int> newdp(n + 1);
        for (int j = 0; j < n; ++j) {
            newdp[j + 1] = newdp[j];
            if (s[j] == t[i]) newdp[j + 1] = add(newdp[j + 1], dp[j]);
        }
        swap(dp, newdp);
    }
    cout << dp[n] << "\n";
    return 0;
}
