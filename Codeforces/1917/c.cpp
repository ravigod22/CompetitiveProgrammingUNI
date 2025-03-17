#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k, d; cin >> n >> k >> d;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        vector<int> v(k);
        for (int& e : v) cin >> e;
        int ans = (d - 1) / 2;
        for (int i = 0; i < n; ++i) if (a[i] == i + 1) ans++;
        vector<int> tmp = a;
        for (int i = 0; i < min(3 * n + 5, d); ++i) {
            int pos = v[i % k];
            int res = (d - i - 2) / 2;
            for (int j = 0; j < pos; ++j) tmp[j]++;
            if (i + 1 < d) for (int j = 0; j < n; ++j) if (tmp[j] == j + 1) res++;
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}

