#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        i64 ans = accumulate(a.begin(), a.end(), 0LL);
        for (int j = 1; j <= x; ++j) {
            multiset<i64> s;
            for (int i = 0; i < n; ++i) {
                if (i >= j) {
                    i64 cur = *s.begin();
                    s.extract(cur);
                    s.insert(cur + a[i]);
                }
                else s.insert(a[i]);
            }
            i64 last = *(--s.end());
            ans = min(ans, last);
        }
        cout << ans << "\n";
    }
    return 0;
}
