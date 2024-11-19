#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m, d; cin >> n >> m >> d;
        vector<int> p(n);
        vector<int> a(m);
        vector<int> pos(n + 1);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            pos[p[i]] = i + 1;
        }
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        bool good = false;
        int ans = 2e9;
        for (int i = 1; i < m; ++i) {
            int tmp = pos[a[i]] - pos[a[i - 1]];
            if (pos[a[i]] > pos[a[i - 1]] && tmp <= d) {
                ans = min(ans, tmp);
                int dis1 = pos[a[i - 1]] - 1;
                int dis2 = n - pos[a[i]];
                if (dis1 + dis2 + tmp > d) {
                    ans = min(ans, d + 1 - tmp);
                }
            }
            else good = true;
        }
        if (good) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
