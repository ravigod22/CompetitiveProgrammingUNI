#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const i64 mod = 998244353;
i64 add(i64 a, i64 b) {
    a %= mod;
    b %= mod;
    return (a + b) % mod;
}
i64 res(i64 a, i64 b) {
    a %= mod;
    b %= mod;
    return (a - b + mod) % mod;
}

i64 mul(i64 a, i64 b) {
    a %= mod;
    b %= mod;
    return a * b % mod;
}
i64 binpow(i64 a, i64 e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

i64 inv(i64 e) {
    return binpow(e, mod - 2);
}

i64 sumsquare(i64 n) {
    i64 res = 1;
    n %= mod;
    res = mul(res, n);
    res = mul(res, n + 1);
    res = mul(res, 2 * n + 1);
    res = mul(res, inv(6));
    return res;
}

void solve() {
    i64 A, B; cin >> A >> B;
    if (A > B) swap(A, B);
    i64 p3 = sqrtl(A + B);
    i64 p2 = sqrtl(B);
    i64 p1 = sqrtl(A);
    // 0 <= C <= maxe
    i64 ans = 0;
    i64 f1 = sumsquare(p1);
    i64 f2 = sumsquare(p2);
    i64 f3 = sumsquare(p3);
    i64 d1 = p1, d2 = p2 - p1, d3 = p3 - p2;
    ans = add(ans, f1);
    ans = add(ans, mul(d2, A));
    ans = add(ans, res(mul(d3, add(A, B)), res(f3, f2)));
    ans = add(ans, p3 + 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


