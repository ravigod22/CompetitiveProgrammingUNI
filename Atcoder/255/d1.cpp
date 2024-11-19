#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x, a, d, n;
    cin >> x >> a >> d >> n;
    x -= a;
    long long l = 0, r = d * (n - 1);
    if (l > r) swap(l, r);
    if (x <= l) {
        cout << l - x;
        return 0;
    }
    if (r <= x) {
        cout << x - r;
        return 0;
    }
    x = (x < 0 ? -x : x);
    d = (d < 0 ? -d : d);
    if (d != 0) cout << min(x % d, d - x % d);
    else cout << x;
    return 0;
}

