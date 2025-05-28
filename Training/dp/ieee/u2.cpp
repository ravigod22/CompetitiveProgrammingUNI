#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int choose[n];
    for (int i = 0; i < n; ++i) cin >> choose[i];
    int dp[k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k : {0, 1}) {
                if (i >= choose[j]) dp[i][k] |= 1 ^ dp[i - choose[j]][k ^ 1];
            }
        }
    }
    cout << (dp[k][0] ? "First" : "Second") << "\n";
    return 0;
}
