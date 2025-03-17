#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (auto&[l, r] : a) cin >> l >> r;
        vector<int> points[51];
        for (int i = 0; i < n; ++i) {
            auto [l, r] =  a[i];
            for (int j = l; j <= r; ++j) points[j].emplace_back(i);
        }
        if (points[k].empty()) {
            cout << "NO\n";
            continue;
        }
        bool can = true;
        sort(points[k].begin(), points[k].end());
        for (int i = 1; i <= 50; ++i) {
            sort(points[i].begin(), points[i].end());
            if (i == k) continue;
            int p = 0;
            for (int j = 0; j < (int)points[i].size() && p < (int)points[k].size(); ++j) { 
                if (points[i][j] == points[k][p]) p++;
            }
            if (p == (int)points[k].size()) {
                can = false;
                break;
            }
        }
        cout << (can ? "YES" : "NO") << "\n";
    }
    return 0;
}
