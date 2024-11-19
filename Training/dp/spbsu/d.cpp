#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int n;
int a[maxn];
long long prefix[maxn];
long long dp[maxn][maxn];

long long f(int l, int r) {
    if (l == r) return 1ll * a[l];
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = prefix[r] - prefix[l - 1] + max(f(l + 1, r), f(l, r - 1));
    return dp[l][r];
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = 1ll * a[i] + prefix[i - 1];
    }
    cout << f(1, n) << "\n";
    return 0;
}
