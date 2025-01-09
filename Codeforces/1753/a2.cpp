#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> pre(n + 1, 0);
    // Place odd: 1 * , place even: -1 * 
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (i & 1 ? -1 : 1) * a[i];
    }
    auto f = [&] (int l, int r) -> int { 
        int sum = pre[r] - pre[l - 1];
        if (l % 2 == 0) sum = -sum;
        return sum;
    };
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    map<int, int> odd;
    map<int, int> even;
    even[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int sum = pre[i];
        if (odd.count(sum)) {
            
        }
        else if (even.count(-sum)) {
            
        }
        else dp[i] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
