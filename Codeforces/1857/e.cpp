#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.emplace_back(x, i);
    }
    sort(a.begin(), a.end());
    vector<i64> prefix(n, 0);
    for (int i = 0; i < n; ++i) {
        prefix[i] = (i ? prefix[i - 1] : 0LL) + a[i].first;
    }
    auto sum = [&] (int l, int r) -> i64 {
        return prefix[r] - (l ? prefix[l - 1] : 0LL);
    };
    vector<i64> ans(n, 0LL);
    for (int i = 0; i < n; ++i) {
        ans[a[i].second] += 1LL * (i + 1) * (a[i].first + 1) - sum(0, i);
        ans[a[i].second] += sum(i, n - 1) - 1LL * (n - i) * (a[i].first - 1) - 1;
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
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
