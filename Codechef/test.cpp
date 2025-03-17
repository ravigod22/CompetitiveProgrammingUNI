#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    i64 ans = 0;
    map<int, int> mp[4];
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        vector<int> bits;
        for (int j = 29; j >= 0; --j) {
            if ((a[i] >> j) & 1) {
                cnt++;
                bits.push_back(j);
            }
        }
        assert (cnt >= 1);
        ans += 2 * mp[cnt - 1][a[i]] + max(0, i - mp[cnt - 1][a[i]]);
        // cout << "index -> " << i << "\n";
        for (int e : bits) cout << e << " ";
        // cout << endl;
        // cout << "operations -> \n";
        for (int j = 1; j < (1 << cnt); ++j) {
            // cout << "mask -> " << j << "\n";
            int tmp = 0;
            int num = 0;
            for (int k = 0; k < cnt; ++k) {
                if ((j >> k) & 1) {
                    tmp |= 1 << bits[k];
                    num++;
                }
            }
            // cout << "subset -> " << tmp << " , n bits -> " << num << "\n";
            mp[num - 1][tmp]++;
        }
        // cout << "=================================\n";
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
