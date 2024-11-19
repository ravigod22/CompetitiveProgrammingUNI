#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        long long x, y, k; cin >> x >> y >> k;
        long long last = -1;
        while (true) {
            last = x;
            long long ope = (x / y) + 1;
            long long need = ope * y - x;
            if (need > k) {
                x += k;
                break;
            }
            x += need;
            k -= need;
            while (x % y == 0) {
                x /= y;
            }
            if (last == x) {
                //cout << x << "\n";
                k %= need;
            }
        }
        cout << x << "\n";
    }
    return 0;
}

