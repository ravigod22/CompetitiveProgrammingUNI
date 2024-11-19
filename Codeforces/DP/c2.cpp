#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e15;

int main() {
    int n; cin >> n;
    vector<int> vit(n, 0);
    vector<vector<int>> dp(n + 1, vector<int> (1 << 3, inf));
    dp[0][7] = 0;
    for (int i = 0; i < n; ++i) {
        int value; cin >> value;
        string s; cin >> s;
        for (auto e : s) vit[i] |= (1 <<(e - 'A'));
        for (int j = 0; j < 1 << 3; ++j) {
            dp[i + 1][j] = min(dp[i][j | vit[i]] + value, dp[i][j]); 
        }
    }
    cout << (dp[n][0] == inf ? -1 : dp[n][0]);
    return 0;
}

