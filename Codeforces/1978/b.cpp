#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        if (a >= b) {
            long long ans = 1ll * a * n;
            cout << ans << "\n";
        }
        else {
            if (b - a > n) {
                long long k = 0ll + n;
                long long tmp = 1ll * b * k;
                long long tmp2 = 1ll * (k - 1) * k / 2;
                cout << tmp - tmp2 << "\n";
            }
            else {
                long long k = 0ll + b - a;
                long long tmp = 1ll * b * k;
                long long tmp2 = (k - 1) * k / 2;
                long long remain = 0ll + n - k;
                long long tmp3 = 1ll * a * remain;
                cout << (tmp - tmp2) + tmp3 << "\n";
            }
        }
    }
    return 0;
}

