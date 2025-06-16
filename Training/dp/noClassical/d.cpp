#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int W = 2e4 + 5;
const int OFF = 1e4;
const int mod = 1e9 + 7;
int n;
int a[N];
int dp[N][W];

int main() {
    // it wasn't solved
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dp[0][OFF] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < W; ++j) {
            if (j >= a[i]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - a[i]]) % mod;
            if (j + a[i] < W) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j + a[i]]) % mod;
        }    
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = OFF - 10; j <= OFF + 10; ++j)
            cout << dp[i][j] << " ";
        cout << "\n";
    }
    cout << dp[n][OFF] << "\n";
    return 0;    
}
