#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    i64 c; cin >> c;
    vector<int> s(n);
    for (int& e : s)
        cin >> e;
    i64 lo = 0;
    i64 hi = 1e9;
    auto f = [&] (i64 x) -> bool {
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (s[i] + 2 * x) * (s[i] + 2 * x);
            if (ans > 1e18) {
                ans = 1e18;
                break;
            }
        }
        return ans >= c;
    };
    while (lo < hi) {
        i64 mid = (lo + hi) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
