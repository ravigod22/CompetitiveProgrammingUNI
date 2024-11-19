#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int binpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b /= 2;
    }
    return ans;
}

int inverse(int x) {
    return binpow(x, mod - 2);
}
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    int sumsquare = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = add(sum, a[i]);
        sumsquare = add(sumsquare, mul(a[i], a[i]));
    }
    int result = add(mul(sum, sum), mod - sumsquare);
    result = mul(result, inverse(1LL * n * (n - 1) % mod));
    cout << result << "\n";
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
