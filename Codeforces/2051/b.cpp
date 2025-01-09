#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, b, c; cin >> n >> a >> b >> c;
    int total = a + b + c;
    int tmp = n / total;
    int remain = n % total;
    int ans = tmp * 3;
    if (remain <= a && remain > 0) ans++;
    else if (remain <= a + b && remain > a) ans += 2;
    else if (remain <= total && remain > a + b) ans += 3;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

