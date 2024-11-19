#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        int tmp = (n - 1);
        int ans = (tmp * k) + 1;
        cout << ans << "\n";
    }
    return 0;
}
