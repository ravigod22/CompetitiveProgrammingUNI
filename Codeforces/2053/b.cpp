#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string ans(n, '0');
        vector<int> cnt(2 * n + 1, 0);
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            int l, r; cin >> l >> r;
            a[i] = {l, r};
            if (l == r) cnt[l]++;
        }
        vector<int> prefix(2 * n + 1, 0);
        vector<int> pre(2 * n + 1, 0);
        for (int i = 1; i <= 2 * n; ++i) pre[i] = pre[i - 1] + (cnt[i] ? 1 : 0);
        for (int i = 1; i <= 2 * n; ++i) prefix[i] = prefix[i - 1] + (cnt[i] > 1);
        for (int i = 0; i < n; ++i) {
            auto [l, r] = a[i];
            int dis = r - l + 1;
            if (l == r) {
                if (prefix[r] - prefix[l - 1] != dis) ans[i] = '1';
            }   
            else {
                if (pre[r] - pre[l - 1] != dis) ans[i] = '1';
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

