#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        int ans = 2 * min(n, m) + max(n, m) - 2;
        if (n == 1 && m == 1) ans = 0;
        cout << ans << "\n";
    }
    return 0;
}
