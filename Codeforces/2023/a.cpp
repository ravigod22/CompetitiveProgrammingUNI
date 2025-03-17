#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (auto& [x, y] : a)
        cin >> x >> y;
    sort(a.begin(), a.end(), [] (auto& x, auto& y) {
        return x.first + x.second < y.first + y.second;
    });
    for (int i = 0; i < n; ++i) cout << a[i].first << " " << a[i].second << " \n"[i + 1 == n];
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

