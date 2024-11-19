#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int ans = 0;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        for (int i = 0; i < n; i += 2) ans = max(ans, a[i]);
        cout << ans << "\n";
    }
    return 0;
}
