#include <bits/stdc++.h>
using namespace std;
const int maxpow = 25;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int& e : a) cin >> e;
    int st[m][maxpow + 1];
    for (int i = 0; i < m; ++i) st[i][0] = a[i];
    for (int d = 1, p = 1; 2 * p <= m; ++d, p <<= 1) {
        for (int j = 0; j + 2 * p - 1 < m; ++j) {
            st[j][d] = max(st[j][d - 1], st[j + p][d - 1]);
        }
    }
    auto query = [&] (int l, int r) -> int {
        int d = r - l + 1;
        int k = 31 - __builtin_clz(d);
        int p = 1 << k;
        return max(st[l][k], st[r - p + 1][k]);
    };
    int q; cin >> q;
    while (q--) {
        int s[2], f[2], k;
        cin >> s[0] >> s[1] >> f[0] >> f[1] >> k;
        int difx = abs(s[0] - f[0]);
        int dify = abs(s[1] - f[1]);
        if ((difx % k != 0) || (dify % k != 0)) {
            cout << "NO\n";
            continue;
        }
        int maxy = ((n - s[0]) / k) * k + s[0];
        // search the max in [l, r] -> [f[0], f[1]]
        int maxh = query(min(s[1], f[1]) - 1, max(s[1], f[1]) - 1);
        cout << (maxh < maxy ? "YES" : "NO") << "\n";
    }
    return 0;
}
