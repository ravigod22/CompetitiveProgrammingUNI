#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        if (m == 0) {
            cout << n << "\n";
            continue;
        }
        i64 L = 1LL * max(0, n - m);
        i64 R = 0LL + n + m;
        i64 ans = 0;
        for (int i = 32; i >= 0; --i) {
            int bitL = (L >> i) & 1;
            int bitR = (R >> i) & 1;
            if (bitL == bitR) {
                if (bitL) ans |= (1LL << i);
            }
            else {
                ans |= (1LL << (i + 1)) - 1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

