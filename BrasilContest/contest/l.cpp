#include <bits/stdc++.h>
using namespace std;

const int N = 6e5 + 10;
const int mod = 998244353;
int n, k, q, x;
int f[N], invf[N];


int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int binpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

void precomputation() {
    f[0] = f[1] = 1;
    for (int i = 2; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    invf[N - 1] = binpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i) {
        invf[i] = mul(i + 1, invf[i + 1]);
    }
}

int C(int a, int b) {
    return mul(mul(f[a], invf[b]), invf[a - b]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    cin >> n >> k >> q >> x;
    while (q--) {
        int pos, l, r;
        cin >> pos >> l >> r;
        l -= 1, r -= 1;
        int preR = C(pos + r + 1, r);
        int preL = (l ? C(pos + l, l - 1) : 0);
        int ans = add(preR, mod - preL);
        ans = mul(ans, x);
        cout << ans << "\n";
    }
    return 0;
}
