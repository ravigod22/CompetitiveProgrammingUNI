#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        long long k;
        int x, y, z;
        cin >> x >> y >> z >> k;
        long long cnt = 0;
        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                long long tmp = i * j;
                if (k % tmp != 0) continue;
                if ((1ll * k) / tmp > 1ll * z) continue;
                long long p = k / tmp;
                long long op = (x - i + 1) * (y - j + 1) * (z - p + 1);
                cnt = max(cnt, op);
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

