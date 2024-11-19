#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b); 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, a, b; cin >> n >> a >> b;
        vector<int> c(n);
        int tmp = gcd(a, b);
        for (int& e : c) cin >> e, e %= tmp;
        sort(c.begin(), c.end());
        int ans = c[n - 1] - c[0];
        for (int i = 1; i < n; ++i) {
            ans = min(ans, c[i - 1] + tmp - c[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}

