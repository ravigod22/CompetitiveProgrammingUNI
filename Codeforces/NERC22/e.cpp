#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        int ans = 0;
        if (a > b) ans = 1;
        else ans = (a + n - 1) / a;
        cout << ans << "\n";
    }
    return 0;
}

