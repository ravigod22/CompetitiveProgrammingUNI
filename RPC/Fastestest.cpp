#include <bits/stdc++.h>
using namespace std;

void solve() {
    cout << fixed << setprecision(8);
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << 1.0;
        return;
    }
    double p = 100.0 - (1.0 * y);
    double q = 100.0 - (1.0 * x);
    cout << (p * 1.0 * x) / (q * 1.0 * y);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}

