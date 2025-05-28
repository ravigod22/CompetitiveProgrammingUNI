#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int dp[maxn][4][4];


void precomputation() {
    for (int i = 0; i < 4; ++i) dp[1][0][i] = 1;    
    for (int i = 2; i < maxn; ++i) {
        for (int mask2 = 0; mask2 < 4; ++mask2) {
            for (int mask1 = 0; mask1 < 4; ++mask1) {
                for (int j = 0; j < 4; ++j) {
                    dp[i][mask1][mask2] = (dp[i][mask1][mask2] + dp[i - 1][j][mask1]) % mod;
                }
            }
        }
    }
}


int ncount(int n) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum = (sum + dp[n][i][0]) % mod;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        cout << ncount(n) << "\n";
    }
    return 0;
}
