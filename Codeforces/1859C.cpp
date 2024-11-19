#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int max_pr = 0;
        int sum = 0;
        vector<pair<int,int>> result;
        for (int j = 1; j <= i; ++j) {
            result.emplace_back(j, j);
        }
        for (int j = n, k = i + 1; j > i; --j, ++k) {
            result.emplace_back(j, k);
        }
        for (int p = 0; p < n; ++p) {
            max_pr = max(max_pr, result[p].first * result[p].second);
            sum += result[p].first * result[p].second;
        }
        ans = max(ans, sum - max_pr);
        result.clear();
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
