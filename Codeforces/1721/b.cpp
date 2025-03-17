#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, sx, sy, d; cin >> n >> m >> sx >> sy >> d;
        int ans = n + m - 2;
        int xL = max(1, sx - d), xR = min(n, sx + d);
        int yD = max(1, sy - d), yU = min(m, sy + d);
        if ((xL != 1 && yU != m) || (xR != n && yD != 1)) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
