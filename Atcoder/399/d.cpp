#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(2 * n);
    for (int& e : a) cin >> e;
    vector<pair<int, int>> pos(n + 1, {-1, -1});
    for (int i = 0; i < 2 * n; ++i) {
        if (pos[a[i]].first == -1) {
            pos[a[i]].first = i;
        }
        else pos[a[i]].second = i;
    }
    set<pair<int, int>> cnt;
    for (int i = 1; i <= n; ++i) {
        auto [f, s] = pos[i];
        assert (pos[i] != make_pair(-1, -1));
        if (f + 1 == s) continue;
        int L1 = (f > 0 ? a[f - 1] : -1);
        int R1 = a[f + 1];
        int L2 = a[s - 1];
        int R2 = (s == 2 * n - 1 ? -1 : a[s + 1]);
        if (L1 == L2) {
            cnt.emplace(min(L1, a[f]), max(L1, a[f]));
        }
        if (L1 != -1 && L1 == R2) {
            cnt.emplace(min(L1, a[f]), max(L1, a[f]));
        }
        if (R1 == L2 && f + 2 < s - 1) {
            cnt.emplace(min(L2, a[f]), max(L2, a[f]));
        }
        if (R1 == R2) {
            cnt.emplace(min(R2, a[f]), max(R2, a[f]));
        }
    }
    cout << cnt.size() << "\n";
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

