#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<i64> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + a[i];
        map<i64, int> cnt;
        int p = 0, ans = 0;
        while (p < n && a[p] != 0) {
            p++;
            if (prefix[p] == 0) ans += 1; 
        }
        while (p < n) {
            cnt.clear();
            int q = p + 1;
            while (q < n && a[q] != 0) q++;
            for (int i = p + 1; i <= q; ++i) {
                cnt[prefix[i]] += 1;
            }
            int maxe = 0;
            for (auto e : cnt) maxe = max(maxe, e.second);
            ans += maxe;
            p = q;
        }
        cout << ans << "\n";
    }
    return 0;
}
