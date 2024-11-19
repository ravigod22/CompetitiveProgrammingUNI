#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 1) {
        cout << min(x, y) << "\n";
        return;
    }

    int mnt = min(x, y);
    n--;
    int lo = 1;
    int hi = 2e9 + 100;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if ((mid / x) + (mid / y) >= n) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << mnt + lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
