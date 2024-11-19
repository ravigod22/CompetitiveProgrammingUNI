#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        if (min(n, m) == 1 && max(n, m) > 2) {
            cout << -1 << "\n";
            continue;
        }
        int tmp = abs(m - n);
        cout << 2 * (min(n, m) - 1) + 2 * tmp + ((tmp & 1) ? -1 : 0) << "\n";
    }
    return 0;
}
