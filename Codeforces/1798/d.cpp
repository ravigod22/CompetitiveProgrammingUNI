#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> neg, pos;
        int maxe = INT_MIN, mine = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            maxe = max(x, maxe);
            mine = min(x, mine);
            if (x >= 0) pos.emplace_back(x);
            else neg.emplace_back(x);
        }
        sort(neg.begin(), neg.end());
        sort(pos.rbegin(), pos.rend());
        i64 lim = maxe - mine;
        int p = 0;
        int sum = 0;
        vector<int> result;
        for (int i = 0; i < (int)neg.size(); ++i) {
            sum = 0;
            while (p < (int)pos.size() && sum + pos[p] <= abs(neg[i])) {
                result.emplace_back(pos[p]);
                sum += pos[p];
                p++;
            }
            result.emplace_back(neg[i]);
        }
        while (p < (int)pos.size()) result.emplace_back(pos[p++]);
        vector<i64> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i] + result[i], 0LL + result[i]);
        }
        i64 res = *max_element(dp.begin(), dp.end());
        if (res >= lim) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i = 0; i < n; ++i) cout << result[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
