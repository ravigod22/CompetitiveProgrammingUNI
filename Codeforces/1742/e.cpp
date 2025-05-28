#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        vector<int> a(n);
        vector<pair<int, int>> k;
        for (int& e : a) cin >> e;
        for (int i = 0; i < q; ++i) {
            int x; cin >> x;
            k.emplace_back(x, i);
        }
        sort(k.begin(), k.end());
        vector<i64> ans(q);
        int p = 0;
        i64 sum = 0;
        for (int i = 0; i < q; ++i) {
            while (p < n && k[i].first >= a[p]) {
                sum += a[p];
                p++;
            }
            ans[k[i].second] = sum;
        }
        for (int i = 0; i < q; ++i) cout << ans[i] << " \n"[i + 1 == q];
    }
    return 0;
}
