#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        ans += max(0, a[i] - b[i + 1]);
    }
    ans += a.back();
    cout << ans << "\n";
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
