#include <bits/stdc++.h>
using namespace std;

int x, y, k;
void solve() {
    int ans = 0;
    cin >> x >> y >> k;
    long long tmp1 = (x + k - 1) / k;
    long long tmp2 = (y + k - 1) / k;
    if (tmp2 >= tmp1) cout << 2 * tmp2 << "\n";
    else cout << 2 * tmp1 - 1 << "\n";
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

