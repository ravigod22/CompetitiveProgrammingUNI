#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> a(n, vector<int> (m));
        vector<pair<i64, int>> ans(n);
        vector<i64> res;
        for (int i = 0; i < n; ++i) {
            i64 sum = 0;
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                sum += a[i][j];
            }
            ans[i] = {sum, i};
        }
        sort(ans.rbegin(), ans.rend());
        for (auto [sum, pos] : ans) {
            for (int j = 0; j < a[pos].size(); ++j) {
                res.emplace_back(a[pos][j]);
            }
        }
        for (int i = 1; i < (int)res.size(); ++i) {
            res[i] += res[i - 1];    
        }
        i64 sumtotal = accumulate(res.begin(), res.end(), 0LL);
        cout << sumtotal << "\n";
    }
    return 0;
}



