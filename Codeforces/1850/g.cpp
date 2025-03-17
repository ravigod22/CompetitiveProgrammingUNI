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
        map<int, int> diago, antidiago;
        map<int, int> x, y;
        for (int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b;
            x[a]++;
            y[b]++;
            diago[a + b]++;
            antidiago[a - b]++;
        }
        i64 ans = 0;
        for (auto [pos, value] : x) ans += 1LL * value * (value - 1);
        for (auto [pos, value] : y) ans += 1LL * value * (value - 1);
        for (auto [pos, value] : diago) ans += 1LL * value * (value - 1);
        for (auto [pos, value] : antidiago) ans += 1LL * value * (value - 1);
        cout << ans << "\n";
    }
    return 0;
}
