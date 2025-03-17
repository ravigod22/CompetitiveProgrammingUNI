#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
const int mod = 998244353;
int dp[maxn];

int add(int a, int b) {
    return (a + b) % mod;
}

int res(int a, int b) {
    return (a + mod - b) % mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, k; cin >> q >> k;
    dp[0] = 1;
    while (q--) {
        char op; cin >> op;
        int w; cin >> w;
        if (op == '+') {
            // we need to update the state
            // where we'll add the object with new weight
            for (int i = k; i >= w; --i) {
                dp[i] = add(dp[i], dp[i - w]);
            }
        }
        else {
            // we need to update the state
            // where we'll delete that object with new weight
            for (int i = w; i <= k; ++i) {
                dp[i] = res(dp[i], dp[i - w]);
            }
        }
        cout << dp[k] << "\n";
    }
    return 0;
}
