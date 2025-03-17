#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        i64 ans = 0;
        for (int i = 2; i < n; ++i) {
            ans += max(0, a[i]);
        }
        ans += max({a[0] + (n > 1 ? a[1] : 0), a[0], 0});
        cout << ans << "\n";
    }
    return 0;
}
