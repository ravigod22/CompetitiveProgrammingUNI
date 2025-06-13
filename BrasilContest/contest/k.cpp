#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5;

int n;
int a[N];
int dp[N];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int,int> mn; // max_dp
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = 1 + dp[i + 1];
        if (mn.count(a[i])) {
            dp[i] = min(1 + dp[i + 1], 1 + mn[a[i]]);
            mn[a[i]] = min(mn[a[i]], dp[i + 1]);
        } else {
            mn[a[i]] = dp[i + 1];
        }
    }
    cout << dp[0] << "\n";

    return 0;
}
