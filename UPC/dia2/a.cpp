#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        int ans = 2e9;
        for (int i = 0; i + k <= n; ++i) {
            ans = min(ans, a[i + k - 1] - a[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
