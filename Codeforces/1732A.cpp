#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 * 20 + 10;
int n, l = 0;
int a[maxn]; 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int tmp = a[0];
    for (int i = 0; i < n; ++i) {
        tmp = gcd(tmp, a[i]);
    }
    int ans = 3;
    if (tmp == 1) {
        cout << 0 << '\n';
        return;
    }
    if (gcd(tmp, n) == 1) ans = 1;
    else if (gcd(tmp, n - 1) == 1) ans = 2;
    cout <<  ans << "\n";
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
