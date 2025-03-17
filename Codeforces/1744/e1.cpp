#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 gcd(i64 a, i64 b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        i64 a, b, c, d; cin >> a >> b >> c >> d;
        i64 tmp = a * b;
        i64 ans = 1;
        bool find = false;
        for (int i = a + 1; i <= c && !find; ++i) {
            i64 aux = gcd(tmp, i);
            i64 comp = tmp / aux;
            i64 L = (b + 1 + comp - 1) / comp;
            i64 R = d / comp;
            if (L <= R) {
                ans = 1LL * i * L * comp;
                cout << 1LL * i << " " << 1LL * L * comp << "\n";
                find = true;
            }
        }
        if (find) {
            assert (ans % tmp == 0);
            continue;
        }
        cout << -1 << " " << -1 << "\n";
    }
    return 0;
}

