#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> c(n);
    for (int& e : a) cin >> e;
    for (int& e : c) cin >> e;
    vector<pair<int, int>> flower(n);
    for (int i = 0; i < n; ++i) {
        flower[i] = {a[i], c[i]};
    }
    sort(flower.begin(), flower.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        long long k = flower[i].first;
        ans = max(ans, k * min(1LL * flower[i].second, m / (1LL * flower[i].first)));
        if (i + 1 < n) {
            if (flower[i + 1].first == k + 1) {
                long long x = min(1LL * flower[i].second, m / k);
                long long y = min(1LL * flower[i + 1].second, (m - x * k) / (k + 1));
                long long can = (m - x * k) % (k + 1);
                long long miss = min({x, 1LL * flower[i + 1].second - y, can});
                ans = max(x * k + y * (k + 1) + miss, ans);
            }
        }
    }
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
