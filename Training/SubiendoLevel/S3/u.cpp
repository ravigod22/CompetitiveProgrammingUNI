#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int dp[k + 1][2];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= k; ++i) {
        for (int e : a) {
            for (int j : {0, 1}) {
                if (i >= e) dp[i][j] |= 1 ^ dp[i - e][j ^ 1];
            }
        }
    }
    cout << (dp[k][0] ? "First" : "Second") << "\n";
    return 0;
}
