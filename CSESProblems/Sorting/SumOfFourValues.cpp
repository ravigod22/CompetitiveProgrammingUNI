#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n;++i) {
        for (int j = i + 1; j < n; ++j) {
            mp[a[i] + a[j]].emplace_back(i, j);
        }
    }
    for (auto [v, k] : mp) {
        int res = x - v;
        if (!mp.count(res)) continue;
        for (auto [l1, r1] : k) {
            for (auto [l2, r2] : mp[res]) {
                if ((l1 != l2 && l1 != r2) && (r1 != l2 && r1 != r2)) {
                    cout << ++l1 << " " << ++l2 << " " << ++r1 << " " << ++r2 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
