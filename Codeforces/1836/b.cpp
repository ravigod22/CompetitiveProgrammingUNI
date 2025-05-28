#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        i64 n, k, g; cin >> n >> k >> g;
        if (g == 2 or k == 0) {
            cout << 0 << "\n";
            continue;
        }
        i64 buckets = (k * g) / ((g - 1) / 2 );
        i64 lim = min(n - 1, buckets);
        i64 total = lim * ((g - 1) / 2);
        i64 remain = k * g - total;
        i64 r = remain % g;
        if (r >= (g + 1) / 2) total += r - g;
        else total += r;
        cout << total << "\n";
    }
    return 0;
}
