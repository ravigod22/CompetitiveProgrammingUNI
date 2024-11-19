#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int n, m, k, w;
int times(int i, int j) {
    int tmp1 = min(n - k + 1, i) - max(1, i - k + 1) + 1;
    int tmp2 = min(m - k + 1, j) - max(1, j - k + 1) + 1;
    return 1LL * tmp1 * tmp2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> m >> k >> w;
        vector<int> a(w);
        vector<i64> result;
        for (int& e : a) cin >> e;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                result.emplace_back(times(i, j));
            }
        }
        sort(result.rbegin(), result.rend());
        sort(a.rbegin(), a.rend());
        i64 ans = 0;
        for (int i = 0; i < min((int)result.size(), w); ++i) {
            ans += (1LL * a[i] * result[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
