#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, x; cin >> n >> x;
        long long ans = 0;
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; a * b <= n && a + b <= x; ++b) {
                ans += min((n - a * b) / (a + b), x - a - b);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

