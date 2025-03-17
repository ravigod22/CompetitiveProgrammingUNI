#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> x(n);
        for (auto& [l, r] : x) cin >> l >> r;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            if (x[i].first > x[i - 1].second) {
                ans = max(ans, x[i].first - x[i - 1].second);
            }
            else if (x[i].second < x[i - 1].first) {
                ans = max(ans, x[i - 1].first - x[i].second);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

