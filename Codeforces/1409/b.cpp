#include <bits/stdc++.h>
using namespace std;

int a, b, x, y, n;

void solve() {
    cin >> a >> b >> x >> y >> n;
    int lim = a + b - (x + y);
    int k = min(lim, n);
    long long ans;
    int d1 = a - x, d2 = b - y;
    int tmp1 = k - d1, tmp2 = k - d2;
    ans = (d1 >= k ? 1LL * (a - k) * b : 1LL * x * (b - tmp1));
    ans = min(ans, (d2 >= k ? 1LL * (b - k) * a : 1LL * y * (a - tmp2)));
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

