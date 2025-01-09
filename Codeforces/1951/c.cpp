#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<pair<int, int>> a(n, {0, 0});
        for (auto& e : a) cin >> e.first;
        vector<pair<int, int>> tmp = a;
        for (int i = 0; i < n; ++i) tmp[i].second = i;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            int pos = tmp[i].second;
            if (k >= m) {
                a[pos].second = m;
            }
            else {
                a[pos].second = k;
                break;
            }
            k -= m;
        }
        i64 aux = 0;
        i64 ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * a[i].second * (1LL * a[i].first + aux);
            aux += 1LL * a[i].second;
        }
        cout << ans << "\n";
    }
    return 0;
}
