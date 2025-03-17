#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
const u64 inf = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        u64 n, x; cin >> n >> x;
        u64 tmp = n ^ x;
        u64 ans = 0;
        if (n == x && n == 0) {
            cout << 0 << "\n";
            continue;
        }
        if (x == 0) {
            int b = 63 - __builtin_clzll(n);
            cout << (1LL << (b + 1)) << "\n";
            continue;
        }
        if (tmp == 0) {
            cout << n << "\n";
            continue;
        }
        int pos = 63 - __builtin_clzll(tmp);
        for (int i = 63; i > pos; --i) {
            if ((x >> i) & 1LL) ans |= (1LL << i);
        }
        if (ans != x) ans = -1;
        else {
            int b1 = (n >> pos) & 1;
            int b2 = (x >> pos) & 1;
            if (b1 && !b2) {
                if (!((ans >> (pos + 1)) & 1)) ans |= (1LL << (pos + 1));
                else ans = -1;
            }
            else ans = -1;
        }
        if (ans == -1) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
