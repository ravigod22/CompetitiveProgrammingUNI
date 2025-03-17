#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (auto& [x, y] : a) cin >> x;
        for (auto& [x, y] : a) cin >> y;
        sort(a.begin(), a.end(), [&] (auto x, auto y) {
            return (x.first + x.second) > (y.first + y.second);            
        });
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) ans -= a[i].second - 1;
            else ans += a[i].first - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}
