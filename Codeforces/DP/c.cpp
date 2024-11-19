#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e15;

int main() {
    int n; cin >> n;
    vector<int> vitamins(8, inf);
    vector<long long> dp(n + 1, INF);
    for (int i = 0; i < n; ++i) {
        int value; cin >> value;
        string s; cin >> s;
        int pos = 0;
        for (auto e : s) pos |= (1 <<(e - 'A'));
        vitamins[pos] = min(vitamins[pos], value);
        long long ans = INF;
        for (int j = 1; j < (1 << 8); ++j) {
            long long result = 0;
            int tmp = 0;
            for (int k = 0; k < 8; ++k) {
                if (j & (1 << k)) {
                    tmp |= k;
                    result += 0ll + vitamins[k];
                } 
            }
            if (tmp + 1 == (1 << 3)) ans = min(ans, result);
        }
        dp[i + 1] = min(ans, dp[i]);
    }
    cout << (dp[n] >= 1ll * inf ? -1 : dp[n]) << "\n";
    return 0;
}
