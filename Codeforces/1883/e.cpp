#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<i64> a(n);
        for (auto& e : a) cin >> e;
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            while (a[i] < a[i - 1]) {
                a[i] *= 2;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
