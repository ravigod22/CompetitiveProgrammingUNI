#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int>& a) {
    int n = a.size();
    const int inf = 1e9;
    vector<int> dp(n + 1, -inf);
    dp[0] = inf;
    for (int i = 0; i < n; ++i) {
        int ind = upper_bound(dp.begin(), dp.end(), a[i], greater<int>()) - dp.begin();
        if (dp[ind - 1] > a[i] && a[i] > dp[ind]) {
            dp[ind] = a[i];
        }
    }
    int pos = 0;
    for (int i = 1; i < n; ++i) {
        if (dp[i] > -inf) pos = i; 
    }
    return pos;
}


int main() {
    int x;
    int test = 1;
    bool space = false;
    while (true) {
        cin >> x;
        if (x == -1) break;
        vector<int> catcher;
        catcher.emplace_back(x);
        while (cin >> x) {
            if (x == -1) break;
            catcher.emplace_back(x);
        }
        int ans = LIS(catcher);
        cout << (space ? "\n" : "") <<"Test #" << test++ << ":\n";
        cout << "  maximum possible interceptions: " << ans << "\n";
        space = true;
    }
    return 0;
}
