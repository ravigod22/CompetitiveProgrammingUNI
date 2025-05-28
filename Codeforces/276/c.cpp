#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> diff(n + 1, 0);
    while (q--) {
        int l, r; cin >> l >> r;
        l--;
        diff[l] += 1;
        diff[r] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        diff[i] += diff[i - 1];
    }
    sort(a.begin(), a.end());
    sort(diff.begin(), diff.begin() + n);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) ans += 1LL * diff[i] * a[i];
    cout << ans << "\n";
    return 0;
}
